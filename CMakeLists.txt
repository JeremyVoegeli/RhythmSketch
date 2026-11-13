#initialize info
cmake_minimum_required(VERSION 3.14)
cmake_policy(SET CMP0135 NEW)

project(RhythmSketch CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#establish core library of .cpp functions (except main.cpp)
add_library(main_lib
    src/fraction.cpp
    src/measure.cpp
    src/pattern.cpp
    src/renderer.cpp
)

target_include_directories(main_lib PUBLIC include/)

add_executable(main src/main.cpp)
target_link_libraries(main PRIVATE main_lib)

# ---------- TESTING SETUP ----------
option(BUILD_TESTING "build the testing suite" ON)

if(BUILD_TESTING)
    include(FetchContent)

    FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/refs/tags/v1.18.0.zip)

    FetchContent_MakeAvailable(googletest)
    enable_testing()

    add_subdirectory(tests)
endif()

    