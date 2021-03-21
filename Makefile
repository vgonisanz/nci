.PHONY: docs test help build
.DEFAULT_GOAL := help

MAKEFLAGS += --no-print-directory	# Silent the folder in/out in whole Makefile
PYTHON=$(shell which python3)

export OS_NAME:=$(shell uname -s | tr A-Z a-z)
export ROOTDIR:=$(shell pwd)
export CURRENT_VERSION:=$(shell ${PYTHON} -c "import os; about={}; exec(open(os.path.join('conanfile.py')).read(), about); print(about['ConanRecipe'].version)")
export CURRENT_USER:=$(shell id -u ${USER}):$(shell id -g ${USER})

# Artifactory configuration (private pypi repository)
export ARTIFACTORY_USER:=$(or $(ARTIFACTORY_USER), "")
export ARTIFACTORY_PASSWORD:=$(or $(ARTIFACTORY_PASSWORD), "")

export ARTIFACTORY_DOCS_REPOSITORY:=$(or $(ARTIFACTORY_DOCS_REPOSITORY), docs)
export JFROG_CLI_OFFER_CONFIG:=false

# Conan configuration
export CONAN_USER_HOME:=$(or $(CONAN_USER_HOME), ${ROOTDIR})
export CONAN_USER:=$(or $(ARTIFACTORY_USER), "")
export CONAN_PASSWORD:=$(or $(ARTIFACTORY_PASSWORD), "")
export CONAN_URL:=$(or $(CONAN_URL), https://bintray.com/conan/conan-center)
export CONAN_REMOTE:=$(or $(CONAN_REMOTE), conan-center)
export CONAN_SKIP_UPLOAD:=$(or $(CONAN_SKIP_UPLOAD), --skip-upload)
export CONAN_DEV_PROFILE:=$(or $(CONAN_DEV_PROFILE), ".conan/profiles/default") # Use profiles/${OS_NAME}/dev-x86_64 in example

define PRINT_HELP_PYSCRIPT
import re, sys
print("You can run the following targets (with make <target>): \r\n")
for line in sys.stdin:
	match = re.match(r'^([a-zA-Z_-]+):.*?## (.*)$$', line)
	if match:
		target, help = match.groups()
		print("%-20s %s" % (target, help))
endef
export PRINT_HELP_PYSCRIPT

help:
	@${PYTHON} -c "$$PRINT_HELP_PYSCRIPT" < $(MAKEFILE_LIST)

info:
	@echo "Working on OS: ${OS_NAME}"
	@echo "The root dir is: ${ROOTDIR}"
	@echo "The current version is: ${CURRENT_VERSION}"
	@echo "The curent user is: ${CURRENT_USER}"

env-create: ## (re)create a development environment using a Cmake build in Debug 
	@echo "Creating development environment"
	@mkdir -p ${ROOTDIR}/build
	@conan install . -if ${ROOTDIR}/build -pr=${CONAN_DEV_PROFILE}
	@conan build . -bf ${ROOTDIR}/build --configure
	@conan build . -bf ${ROOTDIR}/build --build

build:  ## compile the source-code again
	@[ -d ${ROOTDIR}/build ] || ( echo "${ROOTDIR}/build folder is not created. Use make env-create first."; exit 1 )
	@echo "Building development environment"
	@conan build . -bf ${ROOTDIR}/build --build

run:  ## run the samples
	@[ -d ${ROOTDIR}/build ] || ( echo "${ROOTDIR}/build folder is not created. Use make env-create first."; exit 1 )
	@${ROOTDIR}/build/bin/info_terminal

lint: ## static code analysis with pylint
	@[ -d ${ROOTDIR}/build/lint ] || mkdir -p ${ROOTDIR}/build/lint
	@touch ${ROOTDIR}/build/lint/report.txt
	@echo "Lint analysis"
	@find ${ROOTDIR}/nci -iname "*.cpp" -o -iname "*.h" | xargs cpplint --root=${ROOTDIR}/nci 2>&1 ${ROOTDIR}/build/lint/report.txt || (echo "Linting errors found" )

test: build ## run tests with pytest
	@[ -d ${ROOTDIR}/build ] || ( echo "${ROOTDIR}/build folder is not created. Use make env-create first."; exit 1 )
	@echo "Running tests"
	@CONAN_RUN_TESTS="True" conan build . -bf ${ROOTDIR}/build --test
	@echo "Generated report of tests at: ${ROOTDIR}/build/Testing path"

coverage: test ## check test coverage
	@echo "Running tests for update coverage"
	@$(MAKE) coverage -s -C ${ROOTDIR}/build >> ${ROOTDIR}/build/coverage_report.txt
	@echo "Generated report of coverage at: ${ROOTDIR}/build/coverage/html/index.html"

profiling: test ## check the profiling using tests
	@echo "Running tests for generate profiling data"
	@[ -d ${ROOTDIR}/build/profiling ] || mkdir -p ${ROOTDIR}/build/profiling
	@gprof ${ROOTDIR}/build/bin/run_unit_tests ${ROOTDIR}/build/tests/gmon.out > ${ROOTDIR}/build/profiling/report.txt
	@gprof2dot < ${ROOTDIR}/build/profiling/report.txt | dot -Tsvg -o ${ROOTDIR}/build/profiling/viewer.svg

docs: ## generate project docs
	@$(MAKE) docs -C ${ROOTDIR}/build
	@echo "Generated documentation at: ${ROOTDIR}/build/docs/html/index.html"

version: ## get the current package version
	@echo $(CURRENT_VERSION)

dist: ## create a local distributable
	@CONAN_USER_HOME=~/ CONAN_RUN_TESTS=True conan create conanfile.py nci/${CURRENT_VERSION}@veridas/development -pr=${CONAN_DEV_PROFILE}

clean-all: clean-build clean-dist clean ## remove all build, artifacts and distributables

clean-build: ## remove build artifacts
	@echo "Removing build folder"
	@rm -rf ${ROOTDIR}/build/

clean-dist: ## remove dist packages
	@echo "Removing conan files"
	@rm -rf ${ROOTDIR}/.conan/


