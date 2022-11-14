cmake_minimum_required(VERSION 3.20)

project(demo_stat)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${demo_stat_SOURCE_DIR}/bin)
message(STATUS "demo_stat Output directory: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")


############################################################
# Create an executable
############################################################

# Add an executable with the above sources
add_executable(
        demo_stat
        src/main.cpp
)

