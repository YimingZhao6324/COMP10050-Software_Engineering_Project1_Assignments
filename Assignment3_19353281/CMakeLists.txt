cmake_minimum_required(VERSION 3.15)
project(Assignment3 C)

set(CMAKE_C_STANDARD 99)

find_library(CUNIT libcunit.dll.a D:/Cygwin/lib)
include_directories(D:/Cygwin/usr/include/CUnit)

add_executable(Assignment3 main.c avg_and_max.h avg_and_max.c)


target_link_libraries(Assignment3 PUBLIC ${CUNIT})
