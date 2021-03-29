set(PROJ_NAME input_basic)

project(${PROJ_NAME})

# Module step II: Add the given directories to those the compiler uses to search for include files
# ------------------------------------------------------------------------------------------------------
include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/include )
include_directories( ${PROJECT_NCI_PATH}/modules/core/include )

# Module step III: Create variables with all includes and sources. You can add them manually in a VAR.
# ------------------------------------------------------------------------------------------------------
FILE(GLOB ${PROJ_NAME}_HEADERS
    "include/*.h"
    "include/*.hpp"
)
file(GLOB ${PROJ_NAME}_SRC
    "src/*.c"
    "src/*.cpp"
)

# Module step IV: List of linker search directories. Path to headers needed by the project.
# ------------------------------------------------------------------------------------------------------
#LINK_DIRECTORIES( ${DIR1} ${DIR2} ...)

# Module step V: Create a library using the specified source files and build type in current project.
# ------------------------------------------------------------------------------------------------------

add_executable(${PROJ_NAME} main.cpp)
TARGET_LINK_LIBRARIES(${PROJ_NAME} nci ${CONAN_LIBS} ncurses )
