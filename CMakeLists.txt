# Header
cmake_minimum_required(VERSION 3.15)
project(betterdouble VERSION 0.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# Library
add_library(${CMAKE_PROJECT_NAME} INTERFACE)
target_compile_definitions(${CMAKE_PROJECT_NAME} INTERFACE _USE_MATH_DEFINES)
target_include_directories(${CMAKE_PROJECT_NAME} INTERFACE "$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>" "$<INSTALL_INTERFACE:include>")

# Example
find_package(GTest)
find_package(Eigen3)
if (GTest_FOUND AND Eigen3_FOUND)
    add_executable(example example/example.cpp)
    target_link_libraries(example PUBLIC ${CMAKE_PROJECT_NAME})
    target_link_libraries(example PUBLIC GTest::gtest Eigen3::Eigen)

    add_custom_target(test COMMAND example)
else()
    message(WARNING "GTest/Eigen3 not found, omitting example compilation")
endif()