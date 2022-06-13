set(PROJECT_OPENGL_NAME "${PROJECT_NAME}OpenGL")

file(GLOB GL_ROOT_SOURCE *.cpp)
file(GLOB GL_ROOT_HEADER *.hpp)
file(GLOB GL_BUFFERS_SOURCE buffers/*.cpp)
file(GLOB GL_BUFFERS_HEADER buffers/*.hpp)

# Build the GLAD library
add_library(GLAD SHARED "${PROJECT_SOURCE_DIR}/dependencies/GLAD/src/glad.c")

add_library(${PROJECT_OPENGL_NAME} SHARED
    ${GL_ROOT_SOURCE}
    ${GL_ROOT_HEADER}
    ${GL_BUFFERS_SOURCE}
    ${GL_BUFFERS_HEADER}
)

target_link_libraries(${PROJECT_OPENGL_NAME} PUBLIC
    GLAD
    "${PROJECT_DEPENDENCIES_DIR}/GLFW/lib/libglfw3.a"
)

target_include_directories(${PROJECT_OPENGL_NAME} PUBLIC
    "${PROJECT_BINARY_DIR}"
    "${PROJECT_DEPENDENCIES_DIR}/*/include"
)
