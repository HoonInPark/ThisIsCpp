cmake_minimum_required(VERSION 3.29)
project(Chapter08)

set(CMAKE_CXX_STANDARD 26)

add_executable(FriendFunction FriendFunction.cpp)
add_executable(FriendClass FriendClass.cpp)
add_executable(CompositionSample CompositionSample.cpp)
add_executable(AggregationSample AggregationSample.cpp)
