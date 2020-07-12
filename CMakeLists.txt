cmake_minimum_required(VERSION 3.0.0)
project(relationship VERSION 0.1.0)

include_directories(".")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED)

add_executable(Registry main.cpp Registry.hpp after_idle.hpp)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
