file(GLOB UTILS_ROOT_SOURCE *.cpp)
file(GLOB UTILS_ROOT_HEADER *.hpp)

add_library(${PROJECT_UTILS_NAME} STATIC ${UTILS_ROOT_SOURCE}
                                         ${UTILS_ROOT_HEADER})

target_include_directories(
  ${PROJECT_UTILS_NAME}
  PUBLIC ${PROJECT_BINARY_DIR} ${PROJECT_SOURCE_DIR} ${CMAKE_SOURCE_DIR}
         ${CMAKE_DEPENDENCIES_DIR}/STB/include)

if(${ELLIPSOID_BUILD_SHARED_LIBS})
  add_library(${PROJECT_UTILS_NAME}_DLL SHARED ${UTILS_ROOT_SOURCE}
                                               ${UTILS_ROOT_HEADER})
  target_include_directories(
    ${PROJECT_UTILS_NAME}_DLL
    PUBLIC ${PROJECT_BINARY_DIR} ${PROJECT_SOURCE_DIR} ${CMAKE_SOURCE_DIR}
           ${CMAKE_DEPENDENCIES_DIR}/STB/include)
endif()
