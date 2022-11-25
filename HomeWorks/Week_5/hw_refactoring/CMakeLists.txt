cmake_minimum_required(VERSION 3.20)

project(refactor)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${refactor_SOURCE_DIR}/bin)
message(STATUS "refactor Output directory: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")


############################################################
# Create an executable
############################################################

# Add an executable with the above sources
add_executable(
        refactor
        src/main.cpp
)

