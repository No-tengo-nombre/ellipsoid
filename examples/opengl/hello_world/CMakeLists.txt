set(EXAMPLE_NAME "EXAMPLE_GL_HELLO_WORLD")

add_executable(${EXAMPLE_NAME} main.cpp)
target_link_libraries(${EXAMPLE_NAME} ${PROJECT_OPENGL_NAME})
target_include_directories(${EXAMPLE_NAME} PUBLIC ${CMAKE_SOURCE_DIR})
