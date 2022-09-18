//
// Created by Dmitry Morozov on 21/8/22.
//

#include "shared/Team_Tasks.hpp"

#include <iostream>
#include <tuple>


/**
 * @brief It takes a map from TaskStatus to int and prints the number of tasks in each status
 *
 * @param tasks_info a map of TaskStatus to int. The int is the number of tasks with the corresponding status.
 */
void PrintTasksInfo (TasksInfo tasks_info) {
    std::cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
              ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
              ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
              ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << std::endl;
}


int main () {
    TeamTasks tasks;
    tasks.AddNewTask ("Ilia");
    for (int i = 0; i < 3; ++i) {
        tasks.AddNewTask ("Ivan");
    }
    std::cout << "Ilia's tasks: ";
    PrintTasksInfo (tasks.GetPersonTasksInfo ("Ilia"));
    std::cout << "Ivan's tasks: ";
    PrintTasksInfo (tasks.GetPersonTasksInfo ("Ivan"));

    TasksInfo updated_tasks, untouched_tasks;

    std::tie (updated_tasks, untouched_tasks) =
            tasks.PerformPersonTasks ("Ivan", 2);
    std::cout << "Updated Ivan's tasks: ";
    PrintTasksInfo (updated_tasks);
    std::cout << "Untouched Ivan's tasks: ";
    PrintTasksInfo (untouched_tasks);

    tie (updated_tasks, untouched_tasks) =
            tasks.PerformPersonTasks ("Ivan", 2);
    std::cout << "Updated Ivan's tasks: ";
    PrintTasksInfo (updated_tasks);
    std::cout << "Untouched Ivan's tasks: ";
    PrintTasksInfo (untouched_tasks);

    return 0;
}