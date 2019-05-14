cmake_minimum_required(VERSION 3.13)
project(vk-intern)

set(CMAKE_CXX_STANDARD 17)

add_executable(vk-intern
        count_common_elements.cpp
        count_common_elements_testing.cpp
        gtest-all.cc
        gtest_main.cc)