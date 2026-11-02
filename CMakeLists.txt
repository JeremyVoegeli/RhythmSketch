cmake_minimum_required(VERSION 3.10)

project(RhythmSketch CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(fraction INTERFACE)
target_include_directories(fraction INTERFACE include/)

add_executable(main src/main.cpp)
target_link_libraries(main PRIVATE fraction)