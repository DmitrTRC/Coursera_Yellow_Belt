enable_testing()

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

include_directories(${HW_x_x_Lib_SOURCE_DIR}/include/)
message(STATUS "hw_TeamTasks_Lib Source DIR : ${hw_TeamTasks_Lib_SOURCE_DIR}")


add_executable(hw_TeamTasks_Tests_run
        tracker_test.cpp
        )

target_link_libraries(hw_TeamTasks_Tests_run
        gtest_main
        team_tasks::lib
        )

include(GoogleTest)
gtest_discover_tests(hw_TeamTasks_Tests_run)