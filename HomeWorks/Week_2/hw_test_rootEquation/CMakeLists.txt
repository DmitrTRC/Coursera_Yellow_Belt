cmake_minimum_required(VERSION 3.20)

project(test_rootEq_run)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${test_rootEq_run_SOURCE_DIR}/bin)
message(STATUS "test_rootEq_run Output directory: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

include_directories(include)

############################################################
# Create an executable
############################################################

# Add an executable with the above sources
add_executable(
        test_rootEq_run
        src/main.cpp
)

