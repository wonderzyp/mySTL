cmake_minimum_required(VERSION 3.10)
project(gtestDEMO)

find_package(GTest CONFIG REQUIRED)
set(CMAKE_CXX_STANDARD 17)

add_executable(main vector_test.cc)
target_link_libraries(main PUBLIC GTest::gtest)