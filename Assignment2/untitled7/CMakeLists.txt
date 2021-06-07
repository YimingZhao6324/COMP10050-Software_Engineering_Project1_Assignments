cmake_minimum_required(VERSION 3.15)
project(untitled7 C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled7 main.c game_init.c game_init.h input_output.h input_output.c logic.h logic.c)