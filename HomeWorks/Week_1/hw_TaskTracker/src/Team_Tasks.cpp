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

/*
 * The PerformPersonTasks command arrives with the task_count = 4 parameter, which means that the status is updated for 3 tasks from NEW to IN_PROGRESS and for 1 task from IN_PROGRESS to TESTING.
If you write out the statuses of all tasks in order, and enclose the updated ones in square brackets, then the change can be depicted as follows:

  [NEW, NEW, NEW, IN_PROGRESS,] IN_PROGRESS, TESTING, TESTING, TESTING, TESTING, DONE

  ==>

  [IN_PROGRESS, IN_PROGRESS, IN_PROGRESS, TESTING,] IN_PROGRESS, TESTING, TESTING, TESTING, TESTING, DONE

Thus, the new task statuses will be as follows:

IN_PROGRESS - 3 updated, 1 old

TESTING - 1 updated, 4 old

DONE - 1 old

In this case, you need to return a tuple of 2 dictionaries:

Updated tasks: IN_PROGRESS - 3, TESTING - 1.

Not updated tasks, excluding completed ones: IN_PROGRESS - 1, TESTING - 4.

None of the dictionaries should contain redundant elements, that is, statuses that correspond to zero tasks.

By convention, DONE tasks do not need to be returned in untouched tasks (untouched_tasks).

Note
Updating a dictionary at the same time as iterating over it can lead to unpredictable results. If such a need arises, it is recommended that you first collect information about updates in a separate temporary dictionary, and then apply them to the main dictionary.
 *
 */
std::tuple<TasksInfo, TasksInfo> TeamTasks::PerformPersonTasks (const std::string &person, int task_count) {
    TasksInfo updated_tasks, untouched_tasks;
    TasksInfo &person_tasks = tasks[person];
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
//    //clean updated tasks
//    for (auto &[task, counter]: updated_tasks) {
//        if (counter == 0) {
//            updated_tasks.erase (task);
//        }
//    }
//
//    //clean untouched tasks
//    for (auto &[task, counter]: untouched_tasks) {
//        if (counter == 0) {
//            untouched_tasks.erase (task);
//        }
//    }

    //Update person tasks
    for (auto &[task, counter]: updated_tasks) {
        person_tasks[task] += counter;
    }


    return {updated_tasks, untouched_tasks};
}
