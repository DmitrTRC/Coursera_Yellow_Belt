//
// Created by Dmitry Morozov on 21/8/22.
//

#include "shared/Team_Tasks.hpp"

#include <iostream>
#include <tuple>


// Принимаем словарь по значению, чтобы иметь возможность
// обращаться к отсутствующим ключам с помощью [] и получать 0,
// не меняя при этом исходный словарь
void PrintTasksInfo (TasksInfo tasks_info) {
    std::cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
              ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
              ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
              ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << std::endl;
}

int main () {
    TeamTasks tasks;

    for (int i = 0; i < 5; ++i) {
        tasks.AddNewTask ("Alice");
    }

    PrintTasksInfo (tasks.GetPersonTasksInfo ("Alice"));
    std::cout << "----------------------------------" << std::endl;

    tasks.PerformPersonTasks ("Alice", 5);
    auto [updated_tasks, untouched_tasks] = tasks.PerformPersonTasks ("Alice", 5);
    PrintTasksInfo (updated_tasks);
    PrintTasksInfo (untouched_tasks);
    std::cout << "----------------------------------" << std::endl;


    return 0;
}