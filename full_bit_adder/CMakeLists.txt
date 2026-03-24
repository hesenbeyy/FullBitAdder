cmake_minimum_required(VERSION 3.10)

# Project name and language
project(FullAdder C)

# Use C11 standard
set(CMAKE_C_STANDARD 11)

# Include current directory for header files
include_directories(.)

# Define the executable and its source files
add_executable(FullAdder 
    main.c 
    binary.c 
    octal.c 
    hexadecimal.c
)