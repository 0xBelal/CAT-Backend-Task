//
// Created by belal on 12/14/25.
//
#include <vector>
#include "Task.h"
#include <vector>
#ifndef INC_1__TO_DO_LIST_CLI_TASKREPOSITORY_H
#define INC_1__TO_DO_LIST_CLI_TASKREPOSITORY_H

class TaskRepository
{
    public:
    virtual bool add (Task task) = 0;
    virtual vector<Task> getAll() = 0;
    virtual  Task getTaskById(string id) =0;
    virtual ~TaskRepository() = default;

};

#endif //INC_1__TO_DO_LIST_CLI_TASKREPOSITORY_H