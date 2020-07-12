cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(Seasoning VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_TOOLCHAIN_FILE "C:/Users/Owner/Desktop/ASL/vcpkg-master/scripts/buildsystems/vcpkg.cmake")

# add the executable
add_executable(Seasoning src/main.cpp)
target_include_directories(Seasoning PUBLIC ${PROJECT_SOURCE_DIR}
"C:/Users/Owner/Desktop/ASL/boost_libraries")

enable_testing()

# does the application run
add_test(NAME Runs COMMAND Seasoning)