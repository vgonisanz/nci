cmake_minimum_required (VERSION 3.0)

# include cmake
include(cmake/utils.cmake)

# Project step I: Set up project options, standard & project name
# ------------------------------------------------------------------------------------------------------
project(PROJECT_NCI)

set(CMAKE_CXX_STANDARD 17)

# Run `cmake -LH` to list all options and variables set
option(BUILD_DOC "Use Doxygen to generate documentation" OFF)
option(BUILD_PROFILING "Add profiling flags" OFF)
option(BUILD_TESTS "Option to compile tests" OFF)
option(BUILD_SAMPLES "Option to build samples" OFF)
option(BUILD_COVERAGE "Enable coverage reporting" OFF)

# Project step II: Check guards protection
# ------------------------------------------------------------------------------------------------------
check_project_guards()

# Project step III: Check dependencies and find packages
# ------------------------------------------------------------------------------------------------------
find_package(PkgConfig)                 # For package whose definition is not maintained in CMake

include(CheckCXXCompilerFlag)
include(CheckCXXSourceRuns)

if(BUILD_TESTS)
    include(CTest)
    add_project_testing()
endif()

# Project step IV: Customize project variables with preset design
# ------------------------------------------------------------------------------------------------------
# "Global" variables
set(PROJECT_NCI_INCLUDE_PATH "")
set(PROJECT_NCI_LIB_TARGETS "ncursesw")
set(PROJECT_NCI_LIB_PATHS "")

# Append includes manually (scope not allow to add inside nested add_directories)
list(APPEND PROJECT_NCI_INCLUDE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/modules/nci/include")
list(APPEND PROJECT_NCI_LIB_TARGETS "")

create_project_dist_clean()
configure_project_variables()
configure_project_flags()

set(PROJECT_NCI_BIN_PATH ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

if(BUILD_PROFILING)
    configure_project_profiling()
endif()

if(BUILD_COVERAGE)
    configure_project_coverage()
endif()

# Project step V: Add modules
# ------------------------------------------------------------------------------------------------------
add_subdirectory(modules)

# Project step VI: (OPTIONAL) Add Samples
# ------------------------------------------------------------------------------------------------------
if(BUILD_SAMPLES)
    add_subdirectory(samples)
endif()

# Project step VII: (OPTIONAL) Add tests
# ------------------------------------------------------------------------------------------------------
if(BUILD_TESTS)
    add_subdirectory(tests)
endif()

# Project step VIII: Install libraries
# ------------------------------------------------------------------------------------------------------
install(DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        DESTINATION ${CMAKE_INSTALL_PREFIX} )

# Project step IX: (OPTIONAL) Create documentation
#-------------------------------------------------------------------------------------------------------
if(BUILD_DOC)
    create_documentation_target()
endif()

# Project step X: Printing summary information
# ------------------------------------------------------------------------------------------------------
print_project_info()
create_last_log_target()
message("Profiling: ${BUILD_PROFILING}, Coverage: ${BUILD_COVERAGE}")
