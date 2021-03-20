macro(create_project_dist_clean)
    add_custom_target(distclean
        ${CMAKE_COMMAND} -E cmake_echo_color --cyan "Cleaning all"
        )
    add_custom_command(TARGET distclean
        COMMAND make clean)
endmacro()

###############################################################################
# configure_project_variables:
#   - This macro configure project variables.
#   - The scope of macro is the global, so works with project scope.
###############################################################################
macro(configure_project_variables)
    message(STATUS "Configuring project variables...")

    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_BINARY_DIR}/bin)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_BINARY_DIR}/bin)

    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY})
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY})
endmacro()

###############################################################################
# configure_project_flags
#   - This macro configure flags to Release, debug, profiling...
###############################################################################
macro(configure_project_flags)
    message(STATUS "Configuring project flags...")

    # Debug no optimize
    set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g -O0 -DDEBUG")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0 -DDEBUG")

    # Release optimize code and mark as NDEBUG
    set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -s -O3 -DNDEBUG")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -s -O3 -DNDEBUG")

    # Release with debug use some optimization and mark as NDEBUG
    set(CMAKE_C_FLAGS_RELWITHDEBINFO "${CMAKE_C_FLAGS_RELWITHDEBINFO} -O2 -g -DNDEBUG")
    set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} -O2 -g -DNDEBUG")

    # Minimize size release code stripping code and mark as NDEBUG
    set(CMAKE_C_FLAGS_MINSIZEREL "${CMAKE_C_FLAGS_MINSIZEREL} -Os -DNDEBUG")
    set(CMAKE_CXX_FLAGS_MINSIZEREL "${CMAKE_CXX_FLAGS_MINSIZEREL} -Os -DNDEBUG")
endmacro()

###############################################################################
# add_project_testing
#   - This macro add GTest framework and initialize variables to use it
#   - DEPRECATED with Conan approach.
###############################################################################
macro(add_project_testing)
    # We need thread support
    find_package(Threads REQUIRED)

    # Enable ExternalProject CMake module
    include(ExternalProject)

    # Download and install GoogleTest
    ExternalProject_Add(
        gtest
        URL https://github.com/google/googletest/archive/master.zip
        PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gtest
        # Disable install step
        INSTALL_COMMAND ""
        )

    # Get GTest source and binary directories from CMake project
    ExternalProject_Get_Property(gtest source_dir binary_dir)

    # Create a libgtest target to be used as a dependency by test programs
    add_library(libgtest IMPORTED STATIC GLOBAL)
    add_dependencies(libgtest gtest)

    # Set libgtest properties
    set_target_properties(libgtest PROPERTIES
        "IMPORTED_LOCATION" "${binary_dir}/lib/libgtest.a"
        "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
        )

    # Create a libgmock target to be used as a dependency by test programs
    add_library(libgmock IMPORTED STATIC GLOBAL)
    add_dependencies(libgmock gtest)

    # Set libgmock properties
    set_target_properties(libgmock PROPERTIES
        "IMPORTED_LOCATION" "${binary_dir}/lib/libgmock.a"
        "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
        )

    set(TEST_INCLUDE_PATH   ${source_dir}/googletest/include/
                            ${source_dir}/googlemock/include/)
    set(TEST_LIB_TARGETS    libgtest
                            libgmock)
endmacro()

###############################################################################
# configure_project_profiling
#   - This macro add flags to allow profiling
###############################################################################
macro(configure_project_profiling)
    message(STATUS "Adding profiling flags")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pg")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pg")
endmacro()

###############################################################################
# configure_project_coverage
#   - This macro add flags and create custom targets to coverage
###############################################################################
macro(configure_project_coverage)
    message(STATUS "Adding coverage flags")

    # Add coverage flags
    set(GCC_COVERAGE_COMPILE_FLAGS "-fprofile-arcs -ftest-coverage")
    set(GCC_COVERAGE_LINK_FLAGS "-lgcov")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}" )

    # Create coverage report
    add_custom_target(coverage)
    add_custom_command(TARGET coverage
        COMMAND ${CMAKE_COMMAND} -E cmake_echo_color --green "Generating coverage..."
        COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_BINARY_DIR}/coverage
        COMMAND lcov --capture --directory ${CMAKE_CURRENT_BINARY_DIR}
                     --output-file ${CMAKE_CURRENT_BINARY_DIR}/coverage/coverage.info
        COMMAND lcov --remove ${CMAKE_CURRENT_BINARY_DIR}/coverage/coverage.info
                     --output-file ${CMAKE_CURRENT_BINARY_DIR}/coverage/coverage-processed.info
                     '/usr/include/*'
                     '*/gtest/*'
        COMMAND genhtml ${CMAKE_CURRENT_BINARY_DIR}/coverage/coverage-processed.info --output-directory ${CMAKE_CURRENT_BINARY_DIR}/coverage/html
        )

    # View coverage report
    add_custom_target(coverage-view
        COMMAND firefox ${${PROJ_MAIN_NAME}_COVERAGE_PATH}/html/index.html)

    # Clean coverage report
    add_custom_target(coverage-clean
        COMMAND ${CMAKE_COMMAND} -E cmake_echo_color --green "Cleaning coverage data..."
        COMMAND ${CMAKE_COMMAND} -E remove_directory "${${PROJ_MAIN_NAME}_COVERAGE_PATH}")

    # Force distclean to execute coverage-clean
    add_dependencies(distclean coverage-clean)
endmacro()

###############################################################################
# create_documentation_target:
#   - This function look for documentation dependencies.
#   - Create doc target
###############################################################################
macro(create_documentation_target)
    find_file(DOXYGEN_PLANTUML_JAR_PATH
        NAMES plantuml.jar
        HINTS "/usr/share/plantuml/"
        DOC "Path to PlantUML JAR."
        )

    if(DOXYGEN_PLANTUML_JAR_PATH)
        message(STATUS "PlantUML found at: ${DOXYGEN_PLANTUML_JAR_PATH}")
    else()
        message(WARNING "PlantUML not found. Documentation won't use diagrams")
    endif()

    find_package(Doxygen
             OPTIONAL_COMPONENTS dot mscgen dia
             )

    if(DOXYGEN_FOUND)
        # Any variable with DOXYGEN_ prefix is converted by doxygen_add_docs to file var
        set(DOXYGEN_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/docs)
        set(DOXYGEN_EXCLUDE "${CMAKE_SOURCE_DIR}/build/"
                            "${CMAKE_SOURCE_DIR}/build-android/"
                            )

        doxygen_add_docs( docs
            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
            COMMENT "Generating API documentation with Doxygen"
            )

        # Add clean target
        add_custom_target(docs-clean)
        add_custom_command(TARGET docs-clean
           POST_BUILD
           COMMAND ${CMAKE_COMMAND} -E cmake_echo_color --green "Cleaning documentation..."
           )

        # Force distclean to execute docs-clean
        add_dependencies(distclean docs-clean)

        # Add viewer target
        # View coverage report
        add_custom_target(docs-view
            COMMAND firefox ${${PROJ_MAIN_NAME}_DOCUMENTATION_PATH}/html/index.html)

        message(STATUS "Documentation configured.")
    else()
        message("Doxygen need to be installed to generate the doxygen documentation")
    endif()
endmacro()

###############################################################################
# print_project_info: PROJECT_NAME
#   - Print general info.
#   - Require as $1 the project name
###############################################################################
macro(print_project_info)
    message("\n")
    message("************************************************************************")
    message("* Project: ${PROJ_MAIN_NAME} ")
    message("************************************************************************")
    message("\t - CMAKE_CXX_FLAGS: ${CMAKE_CXX_FLAGS}")
    message("\t - CMake version: ${CMAKE_VERSION}")
    message("\t - Size of void pointer: ${CMAKE_SIZEOF_VOID_P}")
    message("\t - Build type: ${CMAKE_BUILD_TYPE}")
    message("\t - System name: ${CMAKE_SYSTEM_NAME}")
    message("\t - System version: ${CMAKE_SYSTEM_VERSION}")
    message("\t - Compiling for architecture: ${TARGET_ARCHITECTURE}")
    message("\t - Output binary path: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
    message("\t - Output library path: ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")
    message("\n\tNote: Execute 'cmake -L ..' to see all configurable options")
    message("\n")
endmacro()

# Undocumented stuff
########################################################
add_custom_target(author COMMAND echo "vgoni was here!")
