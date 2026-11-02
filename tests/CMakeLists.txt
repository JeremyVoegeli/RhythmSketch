add_executable(run_tests fraction_test.cpp)

target_link_libraries(run_tests
    PRIVATE
        gtest_main
        fraction
)

include(GoogleTest)
gtest_discover_tests(run_tests)