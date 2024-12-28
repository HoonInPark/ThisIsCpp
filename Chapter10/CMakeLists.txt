cmake_minimum_required(VERSION 3.29)
project(Chapter10)

set(CMAKE_CXX_STANDARD 26)

add_executable(Multicatch Multicatch.cpp)
add_executable(ExceptClass ExceptClass.cpp)
add_executable(ExceptStack ExceptStack.cpp)
add_executable(ExceptAlloc ExceptAlloc.cpp)
