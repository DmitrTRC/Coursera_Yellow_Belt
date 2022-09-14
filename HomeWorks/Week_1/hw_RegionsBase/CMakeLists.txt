

project(hw_RegionsBase_Lib)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${hw_RegionsBase_Lib_SOURCE_DIR}/bin)
message(STATUS "hw_RegionsBase Output directory: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")


############################################################
# Create a library
############################################################

#Generate the shared library from the library sources

add_library(hw_RegionsBase_Lib SHARED
        src/Region.cpp
        src/RegionsBase.cpp
        )

add_library(RegionsBase::lib ALIAS hw_RegionsBase_Lib)

target_include_directories(hw_RegionsBase_Lib
        PUBLIC
        ${PROJECT_SOURCE_DIR}/include
        )

############################################################
# Create an executable
############################################################

# Add an executable with the above sources
add_executable(
        hw_RegionsBase_RUN
        src/main.cpp
)

# link the new hello_library target with the hello_binary target
target_link_libraries(hw_RegionsBase_RUN
        PRIVATE
        RegionsBase::lib
        )

# Tests
add_subdirectory(tests)