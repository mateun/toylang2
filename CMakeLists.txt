cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

project(toycompiler)

file(GLOB sources src/*.cpp)

add_executable(tc ${sources})
