cmake_minimum_required(VERSION 3.27)
project(StringCtrlSample)

set(CMAKE_CXX_STANDARD 23)

add_executable(StringCtrlSample main.cpp
        MyString.h
        MyString.cpp
        MyStringEx.h
        MyStringEx.cpp)
