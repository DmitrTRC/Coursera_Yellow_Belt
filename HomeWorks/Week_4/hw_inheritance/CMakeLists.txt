cmake_minimum_required(VERSION 3.20)

project(inheritance)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${inheritance_SOURCE_DIR}/bin)
message(STATUS "inheritance Output directory: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")


############################################################
# Create an executable
############################################################

# Add an executable with the above sources
add_executable(
        inheritance
        src/main.cpp
)

