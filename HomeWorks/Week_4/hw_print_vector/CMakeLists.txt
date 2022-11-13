cmake_minimum_required(VERSION 3.20)

project(print_vector)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${print_vector_SOURCE_DIR}/bin)
message(STATUS "print_vector Output directory: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")


############################################################
# Create an executable
############################################################

# Add an executable with the above sources
add_executable(
        print_vector
        src/main.cpp
)

