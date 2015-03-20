cmake_minimum_required(VERSION 3.1)
project(a3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    gardens.h
    gardensStudent.cpp
    gardensTest.cpp
    Makefile)

add_executable(a3 ${SOURCE_FILES})