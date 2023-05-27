﻿#include <iostream>
#define S std::
#define CO cout << 
#define T Task.
#define SI Size
#define NSI NSize
#define E std::endl
// https ://unetway.com/tutorial/c-data-i-vrema

struct Time {
    int min;
    int hour;
    int day;
    int month;
    int year;
};
const size_t Size = 250;
const size_t NSize = 250;
struct Task {
    char name[NSI];
    char descript[SI];
    int prior;
    Time time;
};

void TaskShow(Task task) {
    S CO "Task:\nName: " << task.name;
    S CO "\nDescription:\n" << task.descript; 
    S CO "\nPriority: " << task.prior;
    S CO "\nDate: " << task.time.day << '\\' << task.time.month << '\\' << task.time.year << "\t" << task.time.hour << ':' << task.time.min;
}
Task TaskEdit(Task task) {
    S CO "Task Editing" << E;

    S CO "Enter name of task(до 50 символов): ";
    S cin.getline(task.name, NSI);

    S CO "Enter task description(до 250 символов): ";
    S cin.getline(task.descript, SI);

    S CO "Enter priority of task(1 - 4): ";
    S cin >> task.prior;

    S CO "Enter date of task:";
    S CO  "Year: ";
    S cin >> task.time.year;
    S CO  "Month: ";
    S cin >> task.time.month;
    S CO  "Day: ";
    S cin >> task.time.day;
    S CO  "Hours: ";
    S cin >> task.time.hour;
    S CO  "Minutes: ";
    S cin >> task.time.min;
    return task;
}
Task TaskAdder(Task task) {
    bool choise = 1;
    Task z = task;
    task = TaskEdit(task);
    TaskShow(task);
    S CO E << "Add task to list?\n1 - Yes\t0 - No\n";
    S cin >> choise;
    system("cls");
    if (choise) {
        S CO "Task added";
        return task;
    }
    else {
        return z;
    }
}
Task* TaskDeleter(Task tasks[], int choosed) {
    for (size_t i = 0; i < SI; i++)
    {
        if (i >= choosed) {
            tasks[i] = tasks[i + 1];
        }
    }
    return tasks;
}

Task TaskEditor(Task task) {
    bool choise = 1;
    Task z = task;
    task = TaskEdit(task);
    TaskShow(task);
    S CO E << "Add changes to list?\n1 - Yes\t0 - No\n";
    S cin >> choise;
    system("cls");
    if (choise) {
        S CO "Task edited";
        return task;
    }
    else {
        return z;
    }
}
int TaskSearch(Task tasks[]) {
    int choose;
    S cin >> choose;
    switch (choose)
    {
    case 1: {
        char search[5], comp[5];
        S cin >> search;
        for (size_t i = 0; i < NSI; i++)
        {
            for (size_t j = 0; j < 5; j++)
            {
                comp[j] = tasks[i].name[j];
            }
            if (strcmp(comp, search) == 0) {
                TasksShower(tasks[i], i);
            }
        }
        S cin >> choose;
        TaskSelected(tasks, choose);
        break;
    }
    case 2: {
        char search[5], comp[5];
        S cin >> search;
        for (size_t i = 0; i < NSI; i++)
        {
            for (size_t j = 0; j < 5; j++)
            {
                comp[j] = tasks[i].descript[j];
            }
            if (strcmp(comp, search) == 0) {
                TasksShower(tasks[i], i);
            }
        }
        S cin >> choose;
        TaskSelected(tasks, choose);
        break;
    }
    case 3: {
        int cmp;
        S cin >> cmp;
        for (size_t i = 0; i < NSI; i++)
        {
            if (cmp == tasks[i].prior) {
                TasksShower(tasks[i], i);
            }
        }
        S cin >> choose;
        TaskSelected(tasks, choose);
        break;
    }
    case 4: {
        int date[5];
        S CO "Enter date:";
        S CO  "Year: ";
        S cin >> date[0];
        S CO  "Month: ";
        S cin >> date[1];
        S CO  "Day: ";
        S cin >> date[2];
        S CO  "Hours: ";
        S cin >> date[3];
        S CO  "Minutes: ";
        S cin >> date[4];
        for (size_t i = 0; i < NSI; i++)
        {
            if (date[0] == tasks[i].time.year && date[1] == tasks[i].time.month && date[2] == tasks[i].time.day && date[3] == tasks[i].time.hour && date[4] == tasks[i].time.min) {
                TasksShower(tasks[i], i);
            }
        }
        S cin >> choose;
        TaskSelected(tasks, choose);

    }
    default:
        break;
    }
}
void TasksShower(Task task, int i) {
    S CO i << "\t" << task.prior << '\t' << task.time.day << '\\' << task.time.month << '\\' << task.time.year << "  " << task.time.hour << ':' << task.time.min << '\t' << task.name << E;
}

Task* TaskSelected(Task tasks[], int i) {
    TaskShow(tasks[i]);
    int choose;
    S cin >> choose;
    switch (choose)
    {
    case 1: {
        TaskEditor(tasks[i]);
        break;
    }
    case 2: {
        TaskDeleter(tasks, i);
        break;
    }
    default:
        return tasks;
        break;
    }
}
void TaskSort() {

}
void TaskMenu(Task tasks[], Time current) {
    S CO E;
    int choise;
    S cin >> choise;
    switch (choise)
    {
    case 1: {
        S cin >> choise;
        TaskSelected(tasks, choise);
        break;
    }
    case 2: {
        S cin >> choise;
        switch (choise)
        {
        case 1: {
            for (size_t i = 0; i < NSI; i++)
            {
                if (current.year == tasks[i].time.year && current.month == tasks[i].time.month && current.day == tasks[i].time.day) {
                    TasksShower(tasks[i], i);
                }
            }
            TaskMenu(tasks, current);
            break;
        }
        case 2: {
            for (size_t i = 0; i < NSI; i++)
            {
                if (current.year == tasks[i].time.year && current.month == tasks[i].time.month && tasks[i].time.day - current.day <= 7) {
                    TasksShower(tasks[i], i);
                }
            }
            TaskMenu(tasks, current);
            break;
        }
        case 3: {
            for (size_t i = 0; i < NSI; i++)
            {
                if (current.year == tasks[i].time.year && current.month == tasks[i].time.month) {
                    TasksShower(tasks[i], i);
                }
            }
            TaskMenu(tasks, current);
            break;
        }
        default:
            break;
        }
    }
    case 3: {

    }
    default:
        break;
    }
}
int main()
{
    setlocale(LC_ALL, "");
    Task* tasks = new Task[5];
    TaskAdder(tasks[0]);
    Time current;
    S CO "Enter curent date:";
    S CO  "Year: ";
    S cin >> current.year;
    S CO  "Month: ";
    S cin >> current.month;
    S CO  "Day: ";
    S cin >> current.day;
    S CO  "Hours: ";
    S cin >> current.hour;
    S CO  "Minutes: ";
    S cin >> current.min;

    for (size_t i = 0; i < NSI; i++)
    {
        TasksShower(tasks[i], i);
    }
}

