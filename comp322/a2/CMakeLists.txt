cmake_minimum_required(VERSION 2.8.4)
project(a2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    flowers.h
    flowersExamples.cpp
    flowersStudent.cpp
    flowersTest.cpp)

add_executable(a2 ${SOURCE_FILES})