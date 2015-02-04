cmake_minimum_required(VERSION 2.8.4)
project(a1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    continued.h
    continuedStudent.cpp
    continuedTest.cpp)

add_executable(a1 ${SOURCE_FILES})