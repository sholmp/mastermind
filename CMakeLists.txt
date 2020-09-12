cmake_minimum_required(VERSION 3.10)
project(Mastermind LANGUAGES CXX)

enable_testing()

add_subdirectory(googletest)
add_subdirectory(src)
add_subdirectory(test)
