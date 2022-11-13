cmake_minimum_required(VERSION 3.20)

project(sets)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${sets_SOURCE_DIR}/bin)
message(STATUS "sets Output directory: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")


############################################################
# Create an executable
############################################################

# Add an executable with the above sources
add_executable(
        sets
        src/main.cpp
)

