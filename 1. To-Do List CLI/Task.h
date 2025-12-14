//
// Created by belal on 12/14/25.
//

#ifndef INC_1__TO_DO_LIST_CLI_TASK_H
#define INC_1__TO_DO_LIST_CLI_TASK_H
#include <string>
#include <iostream>
using namespace  std;

class Task
{

private:
    string id;
    string title;
    string description;

public:

    Task(){}
    Task(string id,string title,string desc) : id(id), title(title), description(desc){}

    string get_id(){return id;}
    string get_title(){return title;}
    string get_description(){return description;}

    void set_id(string id){  this->id = id;}
    void set_title(string title){ this->title = title;}
    void set_description(string desc){this->description = desc;}

};


#endif //INC_1__TO_DO_LIST_CLI_TASK_H