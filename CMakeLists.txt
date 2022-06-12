cmake_minimum_required(VERSION 3.23)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(Ellipsoid VERSION 0.1)
set(PROJECT_DEPENDENCIES_DIR "${PROJECT_SOURCE_DIR}/dependencies")

add_subdirectory(src)
add_subdirectory(examples)
add_subdirectory(test)
