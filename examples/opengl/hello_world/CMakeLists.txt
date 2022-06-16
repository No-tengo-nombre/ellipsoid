set(EXAMPLE_NAME "hello_world")

add_executable(${EXAMPLE_NAME} main.cpp)
target_link_libraries(
  ${EXAMPLE_NAME} PUBLIC GLAD_GL ${PROJECT_OPENGL_NAME} ${PROJECT_UTILS_NAME}
                         ${CMAKE_DEPENDENCIES_DIR}/GLFW/build/src/libglfw3.a)

target_include_directories(
  ${EXAMPLE_NAME}
  PUBLIC ${CMAKE_SOURCE_DIR}
         ${PROJECT_SOURCE_DIR}
         ${CMAKE_DEPENDENCIES_DIR}/GLAD/include
         ${CMAKE_DEPENDENCIES_DIR}/GLFW/include
         ${CMAKE_DEPENDENCIES_DIR}/GLM/include
         ${CMAKE_DEPENDENCIES_DIR}/STB/include)
