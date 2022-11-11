cmake_minimum_required(VERSION 3.20)

project(test_is_palindrome)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${test_is_palindrome_SOURCE_DIR}/bin)
message(STATUS "test_is_palindrome Output directory: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")


############################################################
# Create an executable
############################################################

# Add an executable with the above sources
add_executable(
        test_is_palindrome
        src/main.cpp
)

