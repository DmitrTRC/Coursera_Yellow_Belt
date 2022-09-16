//
// Created by Dmitry Morozov on 17/9/22.
//

#include <iostream>
#include <map>
#include <tuple>


class TeamTasks {

public:

    /// @brief Get info about tasks for certain person
    [[nodiscard]] const TasksInfo &GetPersonTasksInfo (const std::string &person) const;


    /// @brief Add new task ( with NEW status ) for certain person
    void AddNewTask (const std::string &person);


    /// @brief Update statuses for certain person by given number of tasks
    std::tuple<TasksInfo, TasksInfo> PerformPersonTasks (const std::string &person, int task_count);

private:
    std::map<std::string, TasksInfo> _tasks;

};

//----------------------------------------------------------------------------------------------


void TeamTasks::AddNewTask (const std::string &person) {
    _tasks[person][TaskStatus::NEW]++;

}

const TasksInfo &TeamTasks::GetPersonTasksInfo (const std::string &person) const {
    return _tasks.at (person);
}

std::tuple<TasksInfo, TasksInfo> TeamTasks::PerformPersonTasks (const std::string &person, int task_count) {
    TasksInfo updated_tasks, untouched_tasks;
    TasksInfo &person_tasks = _tasks[person];
    for (auto &[task, counter]: person_tasks) {
        if (task_count == 0) {
            untouched_tasks[task] = counter;
            continue;
        }
        if (task == TaskStatus::DONE) {
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

    //clear empty tasks in updated_tasks
    for (auto it = updated_tasks.begin (); it != updated_tasks.end ();) {
        if (it->second == 0) {
            it = updated_tasks.erase (it);
        } else {
            ++it;
        }
    }

    //clear empty tasks in untouched_tasks
    for (auto it = untouched_tasks.begin (); it != untouched_tasks.end ();) {
        if (it->second == 0) {
            it = untouched_tasks.erase (it);
        } else {
            ++it;
        }
    }


    return {updated_tasks, untouched_tasks};
}

