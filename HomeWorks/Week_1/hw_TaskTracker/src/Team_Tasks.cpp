//
// Created by Dmitry Morozov on 15/9/22.
//

#include "shared/Team_Tasks.hpp"

#include <string>


/**
 * It adds a new task to the person's task list
 *
 * @param person The name of the person to whom the task is assigned.
 */
void TeamTasks::AddNewTask (const std::string &person) {
    ++_tasks[person][TaskStatus::NEW];

}

/**
 * It returns the next status in the sequence of statuses
 *
 * @param status the current status of the task.
 *
 * @return The next status in the enum.
 */
TaskStatus TeamTasks::_nextStatus (TaskStatus status) const {

    return static_cast<TaskStatus> (static_cast<int> (status) + 1);
}

/**
 * It returns a const reference to the TasksInfo object for the person with the given name
 *
 * @return A const reference to the TasksInfo object.
 */
const TasksInfo &TeamTasks::GetPersonTasksInfo (const std::string &person) const {
    return _tasks.at (person);
}

/**
 * It removes all tasks with zero quantity from the tasks map
 *
 * @param tasks a map of tasks and their number of unfinished subtasks.
 */
void TeamTasks::_clearTasks (TasksInfo &tasks) {
    for (auto it = tasks.begin (); it != tasks.end ();) {
        if (it->second == 0) {
            it = tasks.erase (it);
        } else {
            ++it;
        }
    }
}

/**
 * It takes a map of tasks and a number of tasks to be updated, and returns a map of tasks with the number of tasks updated
 *
 * @param tasks a map of task statuses to the number of tasks with that status.
 * @param task_count the number of tasks to be updated
 *
 * @return A map of tasks with updated statuses.
 */
TasksInfo TeamTasks::getUpdatedTasks (TasksInfo &tasks, int task_count) {
    TasksInfo _updated_tasks;
    for (TaskStatus status = TaskStatus::NEW;
         status != TaskStatus::DONE;
         status = _nextStatus (status)) {

        _updated_tasks[_nextStatus (status)] = std::min (task_count, tasks[status]);
        task_count -= _updated_tasks[_nextStatus (status)];
    }
    return _updated_tasks;
}

/**
 * It takes a person's tasks and a set of updated tasks, and returns the tasks that were not updated
 *
 * @param person_tasks a map of tasks for a person
 * @param updated_tasks a map of tasks and their statuses, which are to be updated
 *
 * @return A map of untouched tasks.
 */
TasksInfo TeamTasks::getUntouchedTasks (TasksInfo &person_tasks, TasksInfo &updated_tasks) {
    TasksInfo _untouched_tasks;
    for (TaskStatus status = TaskStatus::NEW;
         status != TaskStatus::DONE;
         status = _nextStatus (status)) {
        _untouched_tasks[status] = person_tasks[status] - updated_tasks[_nextStatus (status)];
        person_tasks[status] += updated_tasks[status] - updated_tasks[_nextStatus (status)];
    }
    person_tasks[TaskStatus::DONE] += updated_tasks[TaskStatus::DONE];
    return _untouched_tasks;
}

/*
    * @brief Update statuses for certain person by given number of tasks
    * @param person - person name
    * @param task_count - number of tasks to perform
    * @return tuple of updated and untouched tasks
    */
std::tuple<TasksInfo, TasksInfo> TeamTasks::PerformPersonTasks (const std::string &person, int tasks_to_perform) {

    TasksInfo &person_tasks = _tasks[person];
    auto updated_tasks = getUpdatedTasks (person_tasks, tasks_to_perform);
    auto untouched_tasks = getUntouchedTasks (person_tasks, updated_tasks);

    _clearTasks (updated_tasks);
    _clearTasks (untouched_tasks);
    _clearTasks (person_tasks);


    return {updated_tasks, untouched_tasks};
}






