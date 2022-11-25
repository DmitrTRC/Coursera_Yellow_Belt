cmake_minimum_required(VERSION 3.20)

project(figures)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${figures_SOURCE_DIR}/bin)
message(STATUS "figures Output directory: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")


############################################################
# Create an executable
############################################################

# Add an executable with the above sources
add_executable(
        figures
        src/main.cpp
)

