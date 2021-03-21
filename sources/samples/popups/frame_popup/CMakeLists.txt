set(PROJ_NAME frame_popups)
add_executable(${PROJ_NAME} src/main.cpp)
target_link_libraries(${PROJ_NAME} nci ${CONAN_LIBS} ncurses)

