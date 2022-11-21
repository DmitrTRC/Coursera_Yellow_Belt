cmake_minimum_required(VERSION 3.20)

project(nearest)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${nearest_SOURCE_DIR}/bin)
message(STATUS "nearest Output directory: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")


############################################################
# Create an executable
############################################################

# Add an executable with the above sources
add_executable(
        nearest
        src/main.cpp
)

