cmake_minimum_required(VERSION 3.21)
project(WORDLESolver C)

set(CMAKE_C_STANDARD 99)

add_executable(WORDLESolver srcs/main.c srcs/solver.c includes/solver.h srcs/coreFunctions.c includes/coreFunctions.h srcs/possibleWords.c includes/possibleWords.h srcs/analyzeWords.c includes/analyzeWords.h)
