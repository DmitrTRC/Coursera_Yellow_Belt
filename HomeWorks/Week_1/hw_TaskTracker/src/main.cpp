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

//TODO: Refactor print changes
void PrintTasksChanges (const TasksInfo &tasks_info) {

    for (const auto &[type, count]: tasks_info) {
        if (tasks_info.count(TaskStatus::NEW) > 0) {
            std::cout << count << " " << " new tasks" << std::endl;
        }
        if (tasks_info.count( TaskStatus::IN_PROGRESS) > 0) {
            std::cout << count << " " << " tasks in progress" << std::endl;
        }
        if (tasks_info.count (TaskStatus::TESTING) > 0) {
            std::cout << count << " " << " tasks are being tested" << std::endl;
        }
        if (tasks_info.count  (TaskStatus::DONE) > 0) {
            std::cout << count << " " << " tasks are done" << std::endl;
        }
    }
}


int main () {
    TeamTasks tasks;

    for (int i = 0; i < 5; ++i) {
        tasks.AddNewTask ("Alice");
    }

    PrintTasksInfo (tasks.GetPersonTasksInfo ("Alice"));
    std::cout << "----------------------------------" << std::endl;

    auto [updated, untouched] = tasks.PerformPersonTasks ("Alice", 5);
    PrintTasksInfo (tasks.GetPersonTasksInfo ("Alice"));

    std::cout << "Updated ";
    PrintTasksChanges (updated);
    std::cout << "Untouched ";
    PrintTasksChanges (untouched);
    std::cout << std::endl;
    std::cout << "----------------------------------" << std::endl;


    return 0;
}