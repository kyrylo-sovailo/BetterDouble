# Header
cmake_minimum_required(VERSION 3.15)
project(betterdouble VERSION 0.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)
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

# Installation
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

configure_package_config_file("${CMAKE_SOURCE_DIR}/config.cmake.in"
    "${CMAKE_BINARY_DIR}/${CMAKE_PROJECT_NAME}Config.cmake"
    INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${CMAKE_PROJECT_NAME}")

write_basic_package_version_file("${CMAKE_BINARY_DIR}/${CMAKE_PROJECT_NAME}ConfigVersion.cmake"
    VERSION ${CMAKE_PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion)

install(TARGETS ${CMAKE_PROJECT_NAME}
    EXPORT ${CMAKE_PROJECT_NAME}_targets
    LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
    INCLUDES DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")

install(EXPORT ${CMAKE_PROJECT_NAME}_targets
    FILE "${CMAKE_PROJECT_NAME}Targets.cmake"
    NAMESPACE ${CMAKE_PROJECT_NAME}::
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${CMAKE_PROJECT_NAME}")

install(FILES "include/${CMAKE_PROJECT_NAME}/${CMAKE_PROJECT_NAME}.h"
    DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/${CMAKE_PROJECT_NAME}")

install(FILES "${CMAKE_BINARY_DIR}/${CMAKE_PROJECT_NAME}Config.cmake" "${CMAKE_BINARY_DIR}/${CMAKE_PROJECT_NAME}ConfigVersion.cmake"
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${CMAKE_PROJECT_NAME}")

# Export
export(EXPORT ${CMAKE_PROJECT_NAME}_targets
    FILE "${CMAKE_PROJECT_NAME}Targets.cmake"
    NAMESPACE ${CMAKE_PROJECT_NAME}::)

# Uninstallation
add_custom_target(uninstall WORKING_DIRECTORY "${CMAKE_BUILD_DIR}" COMMAND cmake -P "${CMAKE_SOURCE_DIR}/uninstall.cmake" ${CMAKE_PROJECT_NAME})

# Documentation
find_package(Doxygen)
if (Doxygen_FOUND)
    file(MAKE_DIRECTORY "${CMAKE_SOURCE_DIR}/documentation")
    add_custom_target(doc WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}" COMMAND doxygen)
endif()