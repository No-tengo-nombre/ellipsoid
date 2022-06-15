cmake_minimum_required(VERSION 3.23)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(Ellipsoid VERSION 0.1)
set(CMAKE_DEPENDENCIES_DIR "${CMAKE_SOURCE_DIR}/dependencies")

# Names for the different libraries in the project
set(PROJECT_UTILS_NAME "${PROJECT_NAME}Utils")
set(PROJECT_OPENGL_NAME "${PROJECT_NAME}OpenGL")
set(PROJECT_VULKAN_NAME "${PROJECT_NAME}Vulkan")

option(ELLIPSOID_BUILD_EXAMPLES "Build the examples that come with the package." OFF)
option(ELLIPSOID_BUILD_TESTS "Build the tests that come with the package." OFF)

# Build the GLAD library
add_library(GLAD_GL SHARED ${CMAKE_DEPENDENCIES_DIR}/GLAD/src/gl.c)
target_include_directories(GLAD_GL PRIVATE
    ${CMAKE_DEPENDENCIES_DIR}/GLAD/include
)

add_subdirectory(ellipsoid)

if (ELLIPSOID_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()
if (ELLIPSOID_BUILD_TESTS)
    add_subdirectory(test)
endif()
