#initialize info
cmake_minimum_required(VERSION 3.14)
cmake_policy(SET CMP0135 NEW)

project(RhythmSketch CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#define a library with a header-only file
add_library(headers INTERFACE)
target_include_directories(headers INTERFACE include/)

#define main executable
add_executable(main src/main.cpp)
target_link_libraries(main PRIVATE headers) #link library to main executable

# ---------- TESTING SETUP ----------
option(BUILD_TESTING "build the testing suite" ON)

if(BUILD_TESTING)
    include(FetchContent)

    FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/refs/tags/v1.18.0.zip)

    FetchContent_MakeAvailable(googletest)
    enable_testing()

    add_subdirectory(tests)
endif()

    