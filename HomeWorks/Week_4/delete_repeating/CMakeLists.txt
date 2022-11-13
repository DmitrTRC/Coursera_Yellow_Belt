cmake_minimum_required(VERSION 3.20)

project(del_rep)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${del_rep_SOURCE_DIR}/bin)
message(STATUS "del_rep Output directory: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")


############################################################
# Create an executable
############################################################

# Add an executable with the above sources
add_executable(
        del_rep
        src/main.cpp
)

