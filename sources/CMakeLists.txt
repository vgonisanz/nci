cmake_minimum_required(VERSION 3.3)

project(nci)

include(cmake/utils.cmake)
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()
create_project_dist_clean()
configure_project_variables()
configure_project_flags()

if(CONAN_SETTINGS_BUILD_TYPE STREQUAL "Debug")
    message(STATUS "Adding extra flags for debug purposes")
    configure_project_coverage()
    configure_project_profiling()
endif()

set(PROJECT_NCI_BIN_PATH ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

add_subdirectory(nci)
add_subdirectory(samples)

enable_testing()
add_subdirectory(tests)
create_documentation_target()

print_project_info()