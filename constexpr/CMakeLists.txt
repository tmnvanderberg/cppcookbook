cmake_minimum_required(VERSION 3.1.0)

project (constexpr)
set(CMAKE_CXX_STANDARD 20)

add_executable(constexpr main.cpp constexpr.h)
