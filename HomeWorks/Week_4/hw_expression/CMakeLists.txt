cmake_minimum_required(VERSION 3.20)

project(expression)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${expression_SOURCE_DIR}/bin)
message(STATUS "expression Output directory: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")


############################################################
# Create an executable
############################################################

# Add an executable with the above sources
add_executable(
        expression
        src/main.cpp
)

