message(STATUS "Adding tests")

add_executable(run_unit_tests tests_base.cpp)
target_link_libraries(run_unit_tests nci ${CONAN_LIBS})
add_test(run_unit_tests ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/run_unit_tests)
