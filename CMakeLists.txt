cmake_minimum_required(VERSION 2.8)

project(main)
include_directories(
    ./
)

set(CMAKE_BUILD_TYPE Debug)
list(APPEND CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -std=c++11 ")

add_executable(main
        test.cpp
        MemoryPools.cpp)

target_include_directories(${PROJECT_NAME}
        PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

