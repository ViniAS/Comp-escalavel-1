cmake_minimum_required(VERSION 3.27)
project(CompEscalavel)

set(CMAKE_CXX_STANDARD 17)

add_executable(CompEscalavel main.cpp
                entrada.cpp
                wordprocessor.cpp
                wordprocessor.h
        entrada.h)
