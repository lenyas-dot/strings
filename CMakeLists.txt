cmake_minimum_required(VERSION 3.17)
project(strings)

set(CMAKE_CXX_STANDARD 20)

add_executable(strings main.cpp src/MyString.h src/MainLogic.h)