cmake_minimum_required(VERSION 3.20)

project(Test_Person)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${Test_Person_SOURCE_DIR}/bin)
message(STATUS "Test_Person Output directory: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")


############################################################
# Create an executable
############################################################

# Add an executable with the above sources
add_executable(
        Test_Person
        src/main.cpp
)

