//
// Created by belal on 12/14/25.
//

#ifndef INC_1__TO_DO_LIST_CLI_FILETASKREPO_H
#define INC_1__TO_DO_LIST_CLI_FILETASKREPO_H
#include <filesystem>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "TaskRepository.h"

#include "config.h"
#include "Task.h"

using namespace config;
using namespace std;
class FileTaskRepo : public TaskRepository {
private:
    // bool createTaskFile(string id)
    // {
    //     string fileName = TaskFilePath(id);
    //     fstream file;
    //     file.open(fileName, ios::out);
    //     if (file.is_open())
    //     {
    //
    //         file.close();
    //     }else
    //     {
    //         cout<<"file not created..\n";
    //         return false;
    //     }
    //
    //     ofstream file2;
    //     file2.open(all_id_path,ios::app);
    //     if (file2.is_open())
    //     {
    //         file2<<id<<endl;
    //         file2.close();
    //
    //         return true;
    //     }
    //     return false;
    // }

    bool addToTaskFile(Task task)
    {
        string fileName = TaskFilePath(task.get_id());
        ofstream file;
        file.open(fileName, ios::out);

        if (file.is_open())
        {
            file<<task.get_id()<<endl;
            file<<task.get_title()<<endl;
            file<<task.get_description()<<endl;

            file.close();


            ofstream file2;
            file2.open(ALL_ID_PATH,ios::app);
            if (file2.is_open())
            {
                file2<<task.get_id()<<endl;
                file2.close();
            }
            return true;

        }


        return false;
    }

    Task getTaskFromFile(string id)
    {
        string fileName = TaskFilePath(id);
        ifstream file(fileName);
        vector<string >lines;

        Task task;

        if (file.is_open())
        {
            string line;
            while (getline(file,line))
            {
                lines.push_back(line);
            }

            task.set_id(lines[0]);
            task.set_title(lines[1]);
            task.set_description(lines[2]);
        }

        file.close();

       return task;
    }

    public:
    FileTaskRepo(){}
    bool add(Task task)
    {

        // if (createTaskFile(task.get_id()))
        // {
            return addToTaskFile(task);
        // }
        return false;
    }
    vector<Task> getAll()
    {
        vector<Task> tasks;

        fstream file;
        file.open((ALL_ID_PATH),ios::in);
        vector<string >lines;

        if (file.is_open())
        {
            string line;
            while (getline(file,line))
            {
                tasks.push_back(getTaskFromFile(line));
            }
        }

        file.close();

        return tasks;
    }
    ~FileTaskRepo()
    {

    }
};
#endif //INC_1__TO_DO_LIST_CLI_FILETASKREPO_H