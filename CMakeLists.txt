cmake_minimum_required(VERSION 3.6)
project(TP2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c grafo.c grafo.h vini.c vini.h)
add_executable(TP2 ${SOURCE_FILES})