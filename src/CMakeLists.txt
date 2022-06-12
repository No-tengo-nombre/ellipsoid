add_subdirectory(opengl)
add_subdirectory(vulkan)

add_executable("${PROJECT_NAME}" hello_world.cpp)
target_link_libraries(${PROJECT_NAME} ${PROJECT_OPENGL_NAME})
