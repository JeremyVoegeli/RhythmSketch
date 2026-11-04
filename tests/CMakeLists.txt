add_executable(run_all_tests 
    test_fraction_class.cpp
    test_note_class.cpp
)

target_link_libraries(run_all_tests
    PRIVATE
        gtest_main
        headers
)

include(GoogleTest)
gtest_discover_tests(run_all_tests)