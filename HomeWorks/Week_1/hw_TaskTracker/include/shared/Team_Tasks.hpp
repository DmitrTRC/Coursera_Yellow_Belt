//
// Created by Dmitry Morozov on 15/9/22.
//

#ifndef COURSERA_YELLOW_BELT_DEV_TEAM_TASKS_HPP
#define COURSERA_YELLOW_BELT_DEV_TEAM_TASKS_HPP

#include <map>
#include <string>
#include <tuple>


enum class TaskStatus {
    NEW,          // Newly created task
    IN_PROGRESS,  // Task is being worked on
    TESTING,      // Task is being tested
    DONE          // Task is done

};

/// @brief TaskInfo struct
using TasksInfo = std::map<TaskStatus, int>;

class TeamTasks {

public:

    /// @brief Get info about tasks for certain person
    [[nodiscard]] const TasksInfo &GetPersonTasksInfo (const std::string &person) const;


    /// @brief Add new task ( with NEW status ) for certain person
    void AddNewTask (const std::string &person);


    /// @brief Update statuses for certain person by given number of tasks
    std::tuple<TasksInfo, TasksInfo> PerformPersonTasks (const std::string &person, int task_count);

private:
    TaskStatus _nextStatus (TaskStatus status) const;

    std::map<std::string, TasksInfo> _tasks;

    TasksInfo getUpdatedTasks (TasksInfo &person_tasks, int task_count);

    TasksInfo getUntouchedTasks (TasksInfo &person_tasks, TasksInfo &updated_tasks);

    void _clearTasks (TasksInfo &tasks);

};

#endif //COURSERA_YELLOW_BELT_DEV_TEAM_TASKS_HPP
