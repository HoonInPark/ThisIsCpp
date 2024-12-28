cmake_minimum_required(VERSION 3.29)
project(Chapter11)

set(CMAKE_CXX_STANDARD 26)

add_executable(AddressBook AddressBook.c
        DataManager.h
        DataManager.c
        LinkedList.h
        LinkedList.c)
add_executable(AddressBook_OOP AddressBook_OOP.cpp
        USERDATA.h
        USERDATA.cpp)
