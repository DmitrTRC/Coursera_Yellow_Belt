enable_testing()

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

include_directories(${hw_RegionsBase_Lib_SOURCE_DIR}/include/)
message(STATUS "hw_RegionsBaseLib Source DIR : ${hw_RegionsBase_Lib_SOURCE_DIR}")


add_executable(hw_RegionsBase_Tests_run
        base_test.cpp
        )

target_link_libraries(hw_RegionsBase_Tests_run
        gtest_main
        RegionsBase::lib
        )

include(GoogleTest)
gtest_discover_tests(hw_RegionsBase_Tests_run)