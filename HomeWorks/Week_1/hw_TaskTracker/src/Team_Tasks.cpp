//
// Created by Dmitry Morozov on 15/9/22.
//

#include "shared/Team_Tasks.hpp"


void TeamTasks::AddNewTask (const std::string &person) {
    ++tasks[person][TaskStatus::NEW];

}
