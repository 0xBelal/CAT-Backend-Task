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
        new_task.set_status("not-started");

        return taskRepository->add(new_task);
    }

    vector<Task> listTasks()
    {
        return taskRepository->getAll();
    }

    bool updateStatus(string id,string status)
    {
        Task task = taskRepository->getTaskById(id);
        string fileName = TaskFilePath(task.get_id());
        fstream file;
        file.open(fileName, ios::out);

        if (file.is_open())
        {
            file<<task.get_id()<<endl;
            file<<status<<endl;
            file<<task.get_title()<<endl;
            file<<task.get_description()<<endl;

            task.set_status(status);
            file.close();
            return true;
        }

        return false;
    }
    ~TaskService() {}

};


#endif //INC_1__TO_DO_LIST_CLI_TASKSERVICE_H