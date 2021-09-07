include_directories(${Mastermind_SOURCE_DIR}/src)

add_executable(unit_tests unit_tests.cpp)
target_link_libraries(unit_tests gtest gtest_main mastermind pthread)
add_test(UNIT_TESTS unit_tests)

