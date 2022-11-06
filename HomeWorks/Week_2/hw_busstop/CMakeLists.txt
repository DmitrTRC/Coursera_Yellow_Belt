cmake_minimum_required(VERSION 3.20)

project(busstop_run)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${busstop_run_SOURCE_DIR}/bin)
message(STATUS "busstop_run Output directory: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")


############################################################
# Create an executable
############################################################

# Add an executable with the above sources
add_executable(
        busstop_run
        src/main.cpp
)

