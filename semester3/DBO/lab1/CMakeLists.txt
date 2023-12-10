cmake_minimum_required(VERSION 3.20)
project(DBOLab1_master)

set(CMAKE_CXX_STANDARD 14)

include_directories(Headers)

add_executable(DBOLab1_master
        Headers/Directors.h
        Headers/Movies.h
        Headers/Constants.h
        Headers/Functions.h
        Headers/Errors.h
        Headers/Menu.h
        Headers/Utils.h
        Sources/Directors.cpp
        Sources/Movies.cpp
        Sources/Functions.cpp
        Sources/Errors.cpp
        Sources/Menu.cpp
        Sources/Utils.cpp
        main.cpp)
