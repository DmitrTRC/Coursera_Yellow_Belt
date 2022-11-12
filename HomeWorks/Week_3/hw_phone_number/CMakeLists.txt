cmake_minimum_required(VERSION 3.20)

project(hw_phone_number)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${hw_phone_number_SOURCE_DIR}/bin)
message(STATUS "hw_phone_number Output directory: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

include_directories(.)
############################################################
# Create an executable
############################################################

# Add an executable with the above sources
add_executable(
        hw_phone_number
        src/phone_number.cpp
)

