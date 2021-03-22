set(PROJ_NAME info_terminal)
add_executable(${PROJ_NAME} main.cpp)
target_link_libraries(${PROJ_NAME} nci ${CONAN_LIBS} ncurses)

