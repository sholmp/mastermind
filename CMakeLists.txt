cmake_minimum_required(VERSION 3.10)
project(Mastermind LANGUAGES CXX)

enable_testing()

add_subdirectory(src)

find_package(GTest)

if(${GTest_FOUND})
    add_subdirectory(test)
endif()