# Header
cmake_minimum_required(VERSION 3.15)
project(betterdouble VERSION 0.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Library
add_library(betterdouble INTERFACE)
target_compile_definitions(betterdouble INTERFACE _USE_MATH_DEFINES)
target_include_directories(betterdouble INTERFACE "include")

# Test
find_package(GTest REQUIRED)
find_package(Eigen3 REQUIRED)
add_executable(test test/test.cpp)
target_link_libraries(test PUBLIC betterdouble)
target_link_libraries(test PUBLIC GTest::gtest Eigen3::Eigen)