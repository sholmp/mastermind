include_directories(${Mastermind_SOURCE_DIR}/src)

add_executable(unit_tests unit_tests.cpp)
target_link_libraries(unit_tests gtest_main pthread mastermind)

add_test(UNIT_TESTS unit_tests)

