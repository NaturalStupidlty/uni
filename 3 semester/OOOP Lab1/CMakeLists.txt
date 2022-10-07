cmake_minimum_required(VERSION 3.20)
project(OOOP_Lab1)

set(CMAKE_CXX_STANDARD 14)

add_executable(OOOP_Lab1 main.cpp Source/Graph.h Source/AdjListGraph.h Source/Data.h Source/MatrixGraph.h Source/Errors.cpp Source/Errors.h Source/DateTime.h Source/DateTime.cpp Source/DateTimeConstants.h Source/STime.h Source/STime.cpp)
