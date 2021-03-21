set(PROJ_NAME print_special_keys_ids)
add_executable(${PROJ_NAME} main.cpp)
target_link_libraries(${PROJ_NAME} nci ${CONAN_LIBS} ncurses)

