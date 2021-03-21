set(PROJ_NAME keybinding_usage)
add_executable(${PROJ_NAME} src/main.cpp)
target_link_libraries(${PROJ_NAME} nci ${CONAN_LIBS} ncurses)

