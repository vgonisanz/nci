cmake_minimum_required (VERSION 3.0)

# Test step I: Set up test name
# ------------------------------------------------------------------------------------------------------
set(TEST_NAME test_frames)

project(${TEST_NAME})

# Test step II: Add the given directories to those the compiler uses to search for include files
# ------------------------------------------------------------------------------------------------------
include_directories(${TEST_INCLUDE_PATH})
include_directories( ${PROJECT_NCI_INCLUDE_PATH} )

# Test step III: Create variables with all includes and sources. You can add them manually in a VAR.
# ------------------------------------------------------------------------------------------------------
# For testing we no use HEADERS
file(GLOB ${TEST_NAME}_SRC
    "*.c"
    "*.cpp"
    "../main.cpp"
)

# Test step IV: List of linker search directories. Path to headers needed by the project.
# ------------------------------------------------------------------------------------------------------
#LINK_DIRECTORIES( ${DIR1} ${DIR2} ...)

# Test step V: Create a new test and add it to the group
# ------------------------------------------------------------------------------------------------------
add_executable(${TEST_NAME} ${${TEST_NAME}_SRC} ../test_utils.h)
add_test(NAME ${TEST_NAME}
         COMMAND ${TEST_NAME})

# Test step VI: Link a target to given libraries. Set the name of libraries needed by the project.
# ------------------------------------------------------------------------------------------------------
target_link_libraries(${TEST_NAME}
    ${PROJECT_NCI_LIB_TARGETS}
    ${TEST_LIB_TARGETS}
    )
