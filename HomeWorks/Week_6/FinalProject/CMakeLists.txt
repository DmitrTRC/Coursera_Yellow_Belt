cmake_minimum_required(VERSION 3.20)

project(final)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${final_SOURCE_DIR}/bin)
message(STATUS "final Output directory: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

include_directories(.)

############################################################
# Create an executable
############################################################

# Add an executable with the above sources
add_executable(
        final
        src/main.cpp
        src/date.cpp
        src/database.cpp
        src/node.cpp
        src/condition_parser.cpp
        src/token.cpp
        src/condition_parser_test.cpp
        src/test_runner.cpp
#        src/Helper.h
)

