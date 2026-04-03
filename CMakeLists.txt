cmake_minimum_required(VERSION 3.28)
project(sistemaIluminacao C)

set(CMAKE_C_STANDARD 11)

add_executable(sistemaIluminacao main.c
        sistema.h
        sistema.c)
