//
// Created by belal on 12/14/25.
//

#ifndef INC_1__TO_DO_LIST_CLI_TASKSERVICE_H
#define INC_1__TO_DO_LIST_CLI_TASKSERVICE_H
#include "config.h"
#include "Task.h"
#include "TaskRepository.h"
#include <string>
#include <vector>

using namespace std;
using namespace config;
class TaskService
{

private:
    TaskRepository* taskRepository;

public:
    TaskService(TaskRepository* task_repository) : taskRepository(task_repository){}
    // TaskService()
    bool addTask(std::string title, std::string desc)
    {
        Task new_task;
        new_task.set_title(title);
        new_task.set_description(desc);
        new_task.set_id(generateTaskID());


        return taskRepository->add(new_task);
    }

    vector<Task> listTasks()
    {
        return taskRepository->getAll();
    }

    ~TaskService() {}

};


#endif //INC_1__TO_DO_LIST_CLI_TASKSERVICE_H