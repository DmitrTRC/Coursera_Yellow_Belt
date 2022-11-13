cmake_minimum_required(VERSION 3.20)

project(splitter)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${splitter_SOURCE_DIR}/bin)
message(STATUS "splitter Output directory: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")


############################################################
# Create an executable
############################################################

# Add an executable with the above sources
add_executable(
        splitter
        src/main.cpp
)

