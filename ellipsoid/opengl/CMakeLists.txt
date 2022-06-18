file(GLOB GL_ROOT_SOURCE *.cpp)
file(GLOB GL_ROOT_HEADER *.hpp)
file(GLOB GL_CORE_SOURCE core/*.cpp)
file(GLOB GL_CORE_HEADER core/*.hpp)
file(GLOB GL_BUFFERS_SOURCE buffers/*.cpp)
file(GLOB GL_BUFFERS_HEADER buffers/*.hpp)

add_library(
  ${PROJECT_OPENGL_NAME} STATIC
  ${GL_ROOT_SOURCE} ${GL_ROOT_HEADER} ${GL_CORE_SOURCE} ${GL_CORE_HEADER}
  ${GL_BUFFERS_SOURCE} ${GL_BUFFERS_HEADER})

target_link_libraries(
  ${PROJECT_OPENGL_NAME}
  PUBLIC GLAD_GL ${PROJECT_UTILS_NAME}
         ${CMAKE_DEPENDENCIES_DIR}/GLFW/build/src/libglfw3.a)

target_include_directories(
  ${PROJECT_OPENGL_NAME}
  PUBLIC ${PROJECT_BINARY_DIR}
         ${PROJECT_SOURCE_DIR}
         ${CMAKE_SOURCE_DIR}
         ${CMAKE_DEPENDENCIES_DIR}/GLAD/include
         ${CMAKE_DEPENDENCIES_DIR}/GLFW/include
         ${CMAKE_DEPENDENCIES_DIR}/GLM/include)

if(${ELLIPSOID_BUILD_SHARED_LIBS})
  add_library(
    ${PROJECT_OPENGL_NAME}_DLL SHARED
    ${GL_ROOT_SOURCE} ${GL_ROOT_HEADER} ${GL_CORE_SOURCE} ${GL_CORE_HEADER}
    ${GL_BUFFERS_SOURCE} ${GL_BUFFERS_HEADER})

  target_link_libraries(
    ${PROJECT_OPENGL_NAME}_DLL
    PUBLIC GLAD_GL ${PROJECT_UTILS_NAME}
           ${CMAKE_DEPENDENCIES_DIR}/GLFW/build/src/libglfw3.a)

  target_include_directories(
    ${PROJECT_OPENGL_NAME}_DLL
    PUBLIC ${PROJECT_BINARY_DIR}
           ${PROJECT_SOURCE_DIR}
           ${CMAKE_SOURCE_DIR}
           ${CMAKE_DEPENDENCIES_DIR}/GLAD/include
           ${CMAKE_DEPENDENCIES_DIR}/GLFW/include
           ${CMAKE_DEPENDENCIES_DIR}/GLM/include)
endif()
