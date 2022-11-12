cmake_minimum_required(VERSION 3.20)

project(hw_1_run)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${hw_1_run_SOURCE_DIR}/bin)
message(STATUS "hw_1run Output directory: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

include_directories(.)
############################################################
# Create an executable
############################################################

# Add an executable with the above sources
add_executable(
        hw_1_run
        src/sum_revert_sort.cpp
)

