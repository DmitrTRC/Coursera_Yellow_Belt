cmake_minimum_required(VERSION 3.20)

project(final)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${final_SOURCE_DIR}/bin)
message(STATUS "final Output directory: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")


############################################################
# Create an executable
############################################################

# Add an executable with the above sources
add_executable(
        final
        src/main.cpp
)

