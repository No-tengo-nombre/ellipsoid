cmake_minimum_required(VERSION 3.23)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(Ellipsoid VERSION 0.1)
set(CMAKE_DEPENDENCIES_DIR ${CMAKE_SOURCE_DIR}/dependencies)

# Output for files
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_INCLUDES_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/include)

# Names for the different libraries in the project
set(PROJECT_UTILS_NAME ${PROJECT_NAME}Utils)
set(PROJECT_OPENGL_NAME ${PROJECT_NAME}OpenGL)
set(PROJECT_VULKAN_NAME ${PROJECT_NAME}Vulkan)

option(ELLIPSOID_BUILD_SHARED_LIBS "Build shared libraries." OFF)
option(ELLIPSOID_BUILD_EXAMPLES
       "Build the examples that come with the package." OFF)
option(ELLIPSOID_BUILD_TESTS "Build the tests that come with the package." OFF)
option(ELLIPSOID_INSTALL "Install target." ON)

# Build the GLAD library
add_library(GLAD_GL STATIC ${CMAKE_DEPENDENCIES_DIR}/GLAD/src/gl.c)
target_include_directories(GLAD_GL
                           PRIVATE ${CMAKE_DEPENDENCIES_DIR}/GLAD/include)
add_library(GLAD_VK STATIC ${CMAKE_DEPENDENCIES_DIR}/GLAD/src/vulkan.c)
target_include_directories(GLAD_VK
                           PRIVATE ${CMAKE_DEPENDENCIES_DIR}/GLAD/include)

if(${ELLIPSOID_BUILD_SHARED_LIBS})
  add_library(GLAD_GL_DLL SHARED ${CMAKE_DEPENDENCIES_DIR}/GLAD/src/gl.c)
  target_include_directories(GLAD_GL_DLL
                             PRIVATE ${CMAKE_DEPENDENCIES_DIR}/GLAD/include)
  add_library(GLAD_VK_DLL SHARED ${CMAKE_DEPENDENCIES_DIR}/GLAD/src/vulkan.c)
  target_include_directories(GLAD_VK_DLL
                             PRIVATE ${CMAKE_DEPENDENCIES_DIR}/GLAD/include)
endif()

add_subdirectory(ellipsoid)

if(${ELLIPSOID_BUILD_EXAMPLES})
  add_subdirectory(examples)
endif()
if(${ELLIPSOID_BUILD_TESTS})
  add_subdirectory(test)
endif()

if(${ELLIPSOID_INSTALL})
  install(
    DIRECTORY ${CMAKE_BINARY_DIR}/include/ellipsoid
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIRS}
    FILES_MATCHING
    PATTERN **.hpp
    PATTERN **.h)
endif()
