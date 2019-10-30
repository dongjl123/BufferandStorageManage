include_directories (${PROJECT_INCLUDE_DIR} ../buffer)

add_executable(main main.cpp)
target_link_libraries(main buffer)