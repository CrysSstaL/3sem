cmake_minimum_required(VERSION 3.15)
project(LAB)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include_directories("/")

add_executable(LAB15 Lab15.cpp 15.cpp 15.hpp)
add_executable(LAB16 Lab16.cpp 16.cpp 16.hpp)
add_executable(LAB17 Lab17.cpp 17.cpp 17.hpp)

