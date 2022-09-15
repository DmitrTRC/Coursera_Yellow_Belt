//
// Created by Dmitry Morozov on 15/9/22.
//

#include "shared/Team_Tasks.hpp"

#include <string>


void TeamTasks::AddNewTask (const std::string &person) {
    tasks[person][TaskStatus::NEW]++;

}

const TasksInfo &TeamTasks::GetPersonTasksInfo (const std::string &person) const {
    return tasks.at (person);
}

std::tuple<TasksInfo, TasksInfo> TeamTasks::PerformPersonTasks (const std::string &person, int task_count) {
    TasksInfo updated_tasks, untouched_tasks;
    if (tasks.count (person) == 0) {
        return {updated_tasks, untouched_tasks};
    }

    TasksInfo &person_tasks = tasks[person];
    for (auto &task : person_tasks) {
        TaskStatus status = task.first;
        int count = task.second;

        auto next_status = static_cast<TaskStatus> (static_cast<int> (status) + 1);
        int next_status_count = (next_status == TaskStatus::DONE) ? count : std::min (count, task_count);

        task_count -= next_status_count;
        person_tasks[next_status] += next_status_count;
        person_tasks[status] -= next_status_count;

        if (next_status_count > 0) {
            updated_tasks[next_status] += next_status_count;
        }
        if (person_tasks[status] > 0) {
            untouched_tasks[status] += person_tasks[status];
        }
    }

    if (person_tasks[TaskStatus::DONE] == 0) {
        tasks.erase (person);
    }

    return {updated_tasks, untouched_tasks};

}
