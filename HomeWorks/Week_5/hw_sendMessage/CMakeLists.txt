cmake_minimum_required(VERSION 3.20)

project(msg)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${msg_SOURCE_DIR}/bin)
message(STATUS "msg Output directory: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

include_directories(.)


############################################################
# Create an executable
############################################################

# Add an executable with the above sources
add_executable(
        msg
        src/main.cpp
)

