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
        if (tasks_info.count (TaskStatus::NEW) > 0) {
            std::cout << "NEW : " << count;
        }
        if (tasks_info.count (TaskStatus::IN_PROGRESS) > 0) {
            std::cout << "IN_PROGRESS : " << count << " ,";
        }
        if (tasks_info.count (TaskStatus::TESTING) > 0) {
            std::cout << "TESTING : " << count << " ,";
        }
        if (tasks_info.count (TaskStatus::DONE) > 0) {
            std::cout << "DONE : " << count << " ";
        }
    }
}


int main () {
    TeamTasks tasks;

    for (int i = 0; i < 5; ++i) {
        tasks.AddNewTask ("Alice");
    }
    std::cout << "Added 5 tasks for Alice. " << std::endl;

    PrintTasksInfo (tasks.GetPersonTasksInfo ("Alice"));
    std::cout << "----------------------------------" << std::endl;

    auto [updated, untouched] = tasks.PerformPersonTasks ("Alice", 5);
    std::cout << "Perform Alice 5 tasks" << std::endl;
    PrintTasksInfo (tasks.GetPersonTasksInfo ("Alice"));

    std::cout << "[{";
    PrintTasksChanges (updated);
    std::cout << "}, {";
    PrintTasksChanges (untouched);
    std::cout << "}]" << std::endl;
    std::cout << std::endl;

    std::cout << "New Person statuses : ";
    PrintTasksInfo (tasks.GetPersonTasksInfo ("Alice"));
    std::cout << "----------------------------------" << std::endl;

    auto [updated2, untouched2] = tasks.PerformPersonTasks ("Alice", 5);
    std::cout << "Perform Alice 5 tasks" << std::endl;
    PrintTasksInfo (tasks.GetPersonTasksInfo ("Alice"));

    std::cout << "[{";
    PrintTasksChanges (updated2);
    std::cout << "}, {";
    PrintTasksChanges (untouched2);
    std::cout << "}]" << std::endl;
    std::cout << std::endl;

    std::cout << "New Person statuses : ";
    PrintTasksInfo (tasks.GetPersonTasksInfo ("Alice"));
    std::cout << "----------------------------------" << std::endl;

    //TODO: FIXME: Do not append 1 task do DONE status from updated
    auto [updated3, untouched3] = tasks.PerformPersonTasks ("Alice", 1);
    std::cout << "Perform Alice 1 tasks" << std::endl;
    PrintTasksInfo (tasks.GetPersonTasksInfo ("Alice"));

    std::cout << "[{";
    PrintTasksChanges (updated3);
    std::cout << "}, {";
    PrintTasksChanges (untouched3);
    std::cout << "}]" << std::endl;
    std::cout << std::endl;

    std::cout << "New Person statuses : ";
    PrintTasksInfo (tasks.GetPersonTasksInfo ("Alice"));
    std::cout << "----------------------------------" << std::endl;

    for (int i = 0; i < 5; ++i) {
        tasks.AddNewTask ("Alice");
    }
    std::cout << "Add 5 new tasks for Alice" << std::endl;

    auto [updated4, untouched4] = tasks.PerformPersonTasks ("Alice", 2);
    std::cout << "Perform Alice 2 tasks" << std::endl;
    PrintTasksInfo (tasks.GetPersonTasksInfo ("Alice"));

    std::cout << "[{";
    PrintTasksChanges (updated4);
    std::cout << "}, {";
    PrintTasksChanges (untouched4);
    std::cout << "}]" << std::endl;
    std::cout << std::endl;

    std::cout << "New Person statuses : ";
    PrintTasksInfo (tasks.GetPersonTasksInfo ("Alice"));
    std::cout << "----------------------------------" << std::endl;
    PrintTasksInfo (tasks.GetPersonTasksInfo ("Alice"));
    std::cout << "----------------------------------" << std::endl;

    auto [updated5, untouched5] = tasks.PerformPersonTasks ("Alice", 4);

    std::cout << "Perform Alice 4 tasks" << std::endl;
    PrintTasksInfo (tasks.GetPersonTasksInfo ("Alice"));

    std::cout << "[{";
    PrintTasksChanges (updated5);
    std::cout << "}, {";
    PrintTasksChanges (untouched5);
    std::cout << "}]" << std::endl;
    std::cout << std::endl;

    std::cout << "New Person statuses : ";
    PrintTasksInfo (tasks.GetPersonTasksInfo ("Alice"));
    std::cout << "----------------------------------" << std::endl;

    PrintTasksInfo (tasks.GetPersonTasksInfo ("Alice"));
    std::cout << "----------------------------------" << std::endl;


    return 0;
}