cmake_minimum_required(VERSION 3.29)
project(Chapter11)

set(CMAKE_CXX_STANDARD 26)

add_executable(AddressBook AddressBook.c
        DataManager.h
        DataManager.c
        LinkedList.h
        LinkedList.c
        UserInterface.h
        UserInterface.c)
add_executable(AddressBook_OOP AddressBook_OOP.cpp
        LinkedList_OOP.h
        LinkedList_OOP.cpp
        UserInterface_OOP.h
        UserInterface_OOP.cpp)
