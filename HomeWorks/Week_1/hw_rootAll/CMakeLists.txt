cmake_minimum_required(VERSION 3.20)

project(root_all_run)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${root_all_run_SOURCE_DIR}/bin)
message(STATUS "root_all_run Output directory: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")


############################################################
# Create an executable
############################################################

# Add an executable with the above sources
add_executable(
        root_all_run
        src/main.cpp
)

