cmake_minimum_required(VERSION 3.10)

# Project name and language
project(FullAdder C)

# Use C11 standard
set(CMAKE_C_STANDARD 11)

# Include current directory for header files

target_include_directories(FullAdder PUBLIC include)

# Define the executable and its source files
add_executable(FullAdder 
    src/main.c 
    src/binary.c 
    src/octal.c 
    src/hexadecimal.c
)
