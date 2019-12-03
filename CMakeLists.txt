cmake_minimum_required(VERSION 2.6)
SET(CMAKE_C_COMPILER gcc)
SET(CMAKE_CXX_COMPILER g++)

project(BufferandStorageManage)

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(${CMAKE_SOURCE_DIR}/src/include)

if(CMAKE_BUILD_TYPE MATCHES Debug)
    add_compile_options(-g)
endif(CMAKE_BUILD_TYPE MATCHES Debug)

add_subdirectory(${CMAKE_SOURCE_DIR}/src)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/test)