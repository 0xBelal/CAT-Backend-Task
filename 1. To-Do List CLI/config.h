//
// Created by belal on 12/14/25.
//

#ifndef INC_1__TO_DO_LIST_CLI_CONFIG_H
#define INC_1__TO_DO_LIST_CLI_CONFIG_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>

using namespace  std;

namespace config {


    // const string all_id_path = std::filesystem::current_path().string() + "/all.txt";
    // const string counter_file_path = std::filesystem::current_path().string() + "/counter.txt";
    //
    // const string root_path = "../data/";
    // const string all_id_path = root_path + "all.txt";
    // const string counter_file_path = root_path + "counter.txt";


    namespace fs = std::filesystem;

    const fs::path ROOT_PATH = "/home/belal/Computer Science /Backend/CAT/Back-end_Task/1. To-Do List CLI/data";
    const fs::path ALL_ID_PATH = ROOT_PATH / "all.txt";
    const fs::path COUNTER_FILE_PATH = ROOT_PATH / "counter.txt";


    string TaskFilePath(string id)
    {
        return ROOT_PATH / ( id + ".txt");
    }

    string generateTaskID()
    {
        string id = "";
        int curr_id = 1;
        fstream file;
        file.open(COUNTER_FILE_PATH, ios::in);

        if (!file.is_open()) {
            id = "1";

            fstream file2;
            file2.open(COUNTER_FILE_PATH, ios::out | ios::app);
            file2 << "2";
            file2.close();

        }else
        {
            string line;
            getline(file, line);

            if (!line.empty()) {
                curr_id = stoi(line);
            }

            id = to_string(curr_id);
            curr_id++;

            file.close();
        }

        fstream file3;
        file3.open(COUNTER_FILE_PATH, ios::out);
        file3 << curr_id;
        file3.close();

        return  id;
    }

}

#endif //INC_1__TO_DO_LIST_CLI_CONFIG_H