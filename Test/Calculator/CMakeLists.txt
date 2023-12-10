cmake_minimum_required(VERSION 3.26)
project(Something)

set(CMAKE_CXX_STANDARD 23)

add_executable(Something main.cpp
        core.h
        core.cpp
        Caculate.cpp
        Caculate.h
)
