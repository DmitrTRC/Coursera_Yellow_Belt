cmake_minimum_required(VERSION 3.20)

project(expression)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")

set(CMAKE_OSX_ARCHITECTURES "arm64")

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

add_executable(
        expression2
        src/main2.cpp
)

