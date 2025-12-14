//
// Created by belal on 12/14/25.
//

#ifndef INC_1__TO_DO_LIST_CLI_TASKREPOSITORY_H
#define INC_1__TO_DO_LIST_CLI_TASKREPOSITORY_H

class TaskRepository
{
    public:
    virtual void add(const Task& task) = 0;
    virtual std::vector<Task> getAll() = 0;
    virtual ~TaskRepository() = default;

};

#endif //INC_1__TO_DO_LIST_CLI_TASKREPOSITORY_H