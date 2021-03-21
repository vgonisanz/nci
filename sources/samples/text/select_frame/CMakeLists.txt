add_executable(select_frame src/main.cpp)
target_link_libraries(select_frame nci ${CONAN_LIBS} ncurses)