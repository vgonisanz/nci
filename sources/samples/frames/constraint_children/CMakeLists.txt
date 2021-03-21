set(PROJ_NAME constraint_children_frames)
add_executable(${PROJ_NAME} main.cpp)
target_link_libraries(${PROJ_NAME} nci ${CONAN_LIBS} ncurses)

