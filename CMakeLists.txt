cmake_minimum_required(VERSION 3.16)
project(Tetris C)

set(CMAKE_C_STANDARD 11)

add_executable(Tetris main.c tetris.h tetris.c)