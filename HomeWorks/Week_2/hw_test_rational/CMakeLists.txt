cmake_minimum_required(VERSION 3.20)

project(Test_Rational)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${Test_Rational_SOURCE_DIR}/bin)
message(STATUS "Test_Rational Output directory: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")


############################################################
# Create an executable
############################################################

# Add an executable with the above sources
add_executable(
        Test_Rational
        src/main.cpp
)

