cmake_minimum_required(VERSION 3.31)

project(todo_list
        VERSION 1.0
        DESCRIPTION "A simpel todo list utility"
        LANGUAGES CXX)

add_executable(todo main.cpp functions.cpp)
