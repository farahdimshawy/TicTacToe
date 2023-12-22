cmake_minimum_required(VERSION 3.26)
project(pyramic)

set(CMAKE_CXX_STANDARD 17)

add_executable(pyramic main.cpp
        board.cpp
        board.h
        GameManager.cpp
        Players.cpp
)
