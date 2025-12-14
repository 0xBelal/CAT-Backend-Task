cmake_minimum_required(VERSION 4.1)
project(1__To_Do_List_CLI)

set(CMAKE_CXX_STANDARD 20)

add_executable(1__To_Do_List_CLI main.cpp
        Task.h
        TaskRepository.h
        FileTaskRepo.h
        config.h
        TaskService.h)
