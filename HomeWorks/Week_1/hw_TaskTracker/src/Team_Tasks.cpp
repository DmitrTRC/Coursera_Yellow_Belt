//
// Created by Dmitry Morozov on 15/9/22.
//

#include "shared/Team_Tasks.hpp"

#include <string>
#include <iostream>


void TeamTasks::AddNewTask (const std::string &person) {
    _tasks[person][TaskStatus::NEW]++;

}

const TasksInfo &TeamTasks::GetPersonTasksInfo (const std::string &person) const {
    return _tasks.at (person);
}


/*
 * Failed case #1/102: (Wrong answer)
Неправильный результат в 1 строке

Input:
AddNewTasks Alice 5
PerformPersonTasks Alice 5
PerformPersonTasks Alice 5
PerformPersonTasks Alice 1
AddNewTasks Alice 5
PerformPersonTasks Alice 2
GetPersonTasksInfo Alice
PerformPersonTasks Alice 4
GetPersonTasksInfo Alice

Your output:
[]
[{"NEW": 0, "IN_PROGRESS": 5, "TESTING": 0}, {"NEW": 0, "IN_PROGRESS": 0, "TESTING": 0}]
[{"NEW": 0, "IN_PROGRESS": 0, "TESTING": 5}, {"NEW": 0, "IN_PROGRESS": 0, "TESTING": 0}]
[{"NEW": 0, "IN_PROGRESS": 0, "TESTING": 0, "DONE": 1}, {"NEW": 0, "IN_PROGRESS": 0, "TESTING": 4}]
[]
[{"NEW": 0, "IN_PROGRESS": 2, "TESTING": 0}, {"NEW": 3, "IN_PROGRESS": 0, "TESTING": 4}]
{"NEW": 3, "IN_PROGRESS": 2, "TESTING": 4}
[{"NEW": 0, "IN_PROGRESS": 3, "TESTING": 1}, {"NEW": 0, "IN_PROGRESS": 1, "TESTING": 4}]
{"NEW": 0, "IN_PROGRESS": 4, "TESTING": 5}

Correct output:
[]
[{"IN_PROGRESS": 5}, {}]
[{"TESTING": 5}, {}]
[{"DONE": 1}, {"TESTING": 4}] !!!!!!!!!
[]
[{"IN_PROGRESS": 2}, {"NEW": 3, "TESTING": 4}]
{"NEW": 3, "IN_PROGRESS": 2, "TESTING": 4, "DONE": 1}
[{"IN_PROGRESS": 3, "TESTING": 1}, {"IN_PROGRESS": 1, "TESTING": 4}]
{"IN_PROGRESS": 4, "TESTING": 5, "DONE": 1}

     */
std::tuple<TasksInfo, TasksInfo> TeamTasks::PerformPersonTasks (const std::string &person, int task_count) {
    TasksInfo updated_tasks, untouched_tasks;
    TasksInfo &person_tasks = _tasks[person];
    for (auto &[task, counter]: person_tasks) {
        if (task_count == 0) {
            untouched_tasks[task] = counter;
            continue;
        }

        if (task_count >= counter) {
            updated_tasks[static_cast<TaskStatus>(static_cast<int>(task) + 1)] = counter;
            task_count -= counter;
            counter = 0;
        } else {
            updated_tasks[static_cast<TaskStatus>(static_cast<int>(task) + 1)] = task_count;
            untouched_tasks[task] = counter - task_count;
            task_count = 0;
        }
    }

    for (auto task = TaskStatus::NEW;
         task != TaskStatus::DONE; task = static_cast<TaskStatus>(static_cast<int>(task) + 1)) {
        _tasks[person][task] = updated_tasks[task] + untouched_tasks[task];

    }

    _tasks[person][TaskStatus::DONE] += updated_tasks[TaskStatus::DONE];
    //TODO: remove this line after fixing the bug
    std::cout << "_tasks[person][TaskStatus::DONE  ::  ]" << _tasks[person][TaskStatus::DONE] <<
              ", updated_tasks[TaskStatus::DONE]  ::  " << updated_tasks[TaskStatus::DONE] << std::endl;

    //clear empty tasks in updated_tasks
    for (auto it = updated_tasks.begin (); it != updated_tasks.end ();) {
        if (it->second == 0) {
            it = updated_tasks.erase (it);
        } else {
            ++it;
        }
    }

    //clear empty tasks in untouched_tasks
    untouched_tasks.erase (TaskStatus::DONE);
    for (auto it = untouched_tasks.begin (); it != untouched_tasks.end ();) {
        if (it->second == 0) {
            it = untouched_tasks.erase (it);
        } else {
            ++it;
        }
    }


    return {updated_tasks, untouched_tasks};
}
