//
// Created by Dmitry Morozov on 27/8/22.
//

#include "gtest/gtest.h"

#include "shared/Team_Tasks.hpp"


TEST (TaskTracker, PerformPersonTasks) {
    TeamTasks tasks;

    for (int i = 0; i < 3; ++i) {
        tasks.AddNewTask ("Ivan");
    }

    TasksInfo updated_tasks, untouched_tasks;

    std::tie (updated_tasks, untouched_tasks) =
            tasks.PerformPersonTasks ("Ivan", 2);

    ASSERT_EQ (updated_tasks[TaskStatus::NEW], 0);
    ASSERT_EQ (updated_tasks[TaskStatus::IN_PROGRESS], 2);
    ASSERT_EQ (updated_tasks[TaskStatus::TESTING], 0);
    ASSERT_EQ (updated_tasks[TaskStatus::DONE], 0);

}
