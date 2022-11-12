cmake_minimum_required(VERSION 3.20)

project(hw_decompose2)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${hw_decompose2_SOURCE_DIR}/bin)
message(STATUS "hw_decompose2 Output directory: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

include_directories(.)
############################################################
# Create an executable
############################################################

# Add an executable with the above sources
add_executable(
        hw_decompose2
        src/main.cpp
)

