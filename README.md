# CAT-Backend-Task

### A simple **CLI To-Do List** project in C++ using file-based

## UML Class Diagram

![alt text](<img/Screenshot from 2025-12-14 10-38-33.png>)

## Features

- add tasks with a title and description
- list all tasks

## structure

```
1_To-Do_List_CLI/
├─ main.cpp
├─ Task.h
├─ TaskService.h
├─ TaskRepository.h
├─ FileTaskRepo.h
├─ config.h
├─ data/
│  ├─ all.txt
│  └─ counter.txt
└─ CMakeLists.txt

```

## Running CLI

```
    ./main <command> [args]
```

## Commands

> Add Task

```
    ./main add "<title>" "<description>"
```

> List Tasks

```
    ./main list
```

### Demo

![alt text](<img/Screenshot from 2025-12-14 10-25-34.png>)
