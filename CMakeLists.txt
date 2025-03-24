cmake_minimum_required(VERSION 3.10)
project(Int24Converter C)

set(CMAKE_C_STANDARD 11)

include_directories(inc)

add_executable(test_int24 test/test_int24.c src/int24.c)
