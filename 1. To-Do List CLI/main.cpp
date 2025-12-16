#include  <iostream>
#include "Task.h"
#include "TaskService.h"
#include "TaskRepository.h"
#include "FileTaskRepo.h"


using namespace config;
using namespace std;



void printTasks(vector<Task> vt)
{
    cout<<"==== total tasks = "<<vt.size()<<" ====" <<endl;
    for (Task t: vt)
    {
        cout<<"task #"<<t.get_id()<< "   Status : "<<t.get_status()<<endl;
        cout<<"Title : " << t.get_title()<<endl;
        cout<<"description:\n";
        cout<<"\t" << t.get_description()<<endl;

        cout<<endl;
    }


}
int main(int argc, char* argv[]) {

    if (argc < 2) {
        std::cout << "Usage: ./main <command> [args]\n";
        return 1;
    }

    TaskRepository *repo = new FileTaskRepo();
    TaskService service(repo);

    string cmd = argv[1];

    if (cmd == "add") {
        if (argc < 4) {
            cout << "Usage: ./main add <title> <description>\n";
            return 0;
        }

        if (service.addTask((argv[2]), argv[3]))
            cout << "Task added successfully....\n";
        else
            cout << "Error while adding task....\n";

    }
    else if (cmd == "list") {
        vector<Task> tasks = service.listTasks();
        printTasks(tasks);
    }else if (cmd == "status") // status id <done,in-progress,not-start>
    {

        if (service.updateStatus(argv[2], argv[3]))
        {
            cout<< "Task status update successfully...\n";
        }else
        {
            cout<< "Error while updating task status....\n";
        }
    }
    else {
        cout << "Unknown command: " << cmd << "\n";
    }


    delete repo;

    //
    //
    // TaskRepository *repo = new FileTaskRepo();
    // TaskService service(repo);
    //
    // service.addTask("CAT","task");
    // printTasks(service.listTasks());
    //
    // return 0;
return 0;
}
