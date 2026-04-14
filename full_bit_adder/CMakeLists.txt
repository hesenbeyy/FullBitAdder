cmake_minimum_required(VERSION 3.10)

project(FullAdder C)

set(CMAKE_C_STANDARD 11)

# 1. Define the executable FIRST
add_executable(FullAdder 
    src/main.c 
    src/binary.c 
    src/octal.c 
    src/hexadecimal.c
)

# 2. THEN tell CMake where to find the headers for that executable
target_include_directories(FullAdder PUBLIC include)
