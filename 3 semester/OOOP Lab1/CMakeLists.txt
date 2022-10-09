cmake_minimum_required(VERSION 3.20)
project(OOOP_Lab1)

set(CMAKE_CXX_STANDARD 14)

add_executable(OOOP_Lab1 main.cpp
        Source/Headers/Graph.h
        Source/Headers/AdjListGraph.h
        Source/Headers/Data.h
        Source/Headers/MatrixGraph.h
        Source/Headers/DateTime.h
        Source/Cpp/DateTime.cpp
        Source/Headers/DateTimeConstants.h
        Source/Headers/STime.h
        Source/Cpp/STime.cpp
        Source/Headers/doctest.h
        Source/Cpp/MatrixGraphTesting.cpp
        Source/Cpp/AdjListGraphTesting.cpp)
