cmake_minimum_required(VERSION 3.23)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(Ellipsoid VERSION 0.1)
set(PROJECT_DEPENDENCIES_DIR "${PROJECT_SOURCE_DIR}/dependencies")

option(ELLIPSOID_BUILD_EXAMPLES "Build the examples that come with the package." ON)
option(ELLIPSOID_BUILD_TESTS "Build the tests that come with the package." ON)

# Build the GLAD library
add_library(GLAD_GL SHARED "${PROJECT_SOURCE_DIR}/dependencies/GLAD/src/gl.c")
target_include_directories(GLAD_GL PRIVATE
    "${PROJECT_DEPENDENCIES_DIR}/GLAD/include"
)

add_subdirectory(src)
add_subdirectory(examples)
add_subdirectory(test)
