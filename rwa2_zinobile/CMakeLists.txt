cmake_minimum_required(VERSION 3.20.0)
project(kitting VERSION 0.1.0)


# Compilation flags
add_compile_options(-Wall -pedantic-errors)

#Include header files
include_directories(kitting/include)

# Add executable
add_executable(kitting kitting/src/kitting.cpp kitting/src/main.cpp)
#add_executable(main kitting/src/main.cpp)

# Set C++ standard to C++17
set_property(TARGET kitting PROPERTY CXX_STANDARD 17)


