#include <iostream>
#define S std::
#define CO cout << 
#define T Task.
#define SI Size
#define SS NSize
#define E std::endl
#define CL system("cls");
#define SH S CO "id" << '\t' << "Prior" << '\t' << "Date" << "\t\t" << "Time" << '\t' << "Name" << E;

struct Time {
    int min;
    int hour;
    int day;
    int month;
    int year;
};
const size_t Size = 250;
const size_t NSize = 50;
struct Task {
    char name[SS];
    int prior;
    char descript[SI];
    Time time;
};



void TaskShow(Task task) {
    S CO "Task:\nName: " << task.name;
    S CO "\nDescription:\n" << task.descript; 
    S CO "\nPriority: " << task.prior;
    S CO "\nDate: " << task.time.day << '\\' << task.time.month << '\\' << task.time.year << "\t" << task.time.hour << ':' << task.time.min;
}





Task TaskEdit(Task task) {
    CL
    S CO "Task Editing" << E;
    S cin.getline(task.name, SS);
    S CO "Enter name of task(до 50 символов): ";
    S cin.getline(task.name, SS);
    
    S CO "Enter priority of task(1 - 4): ";
    S cin >> task.prior;
    S cin.getline(task.descript, SI);
    S CO "Enter task description(до 250 символов): ";
    S cin.getline(task.descript, SI);

    S CO "Enter date of task:" << E;
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
    CL
    if (choise) {
        S CO "Task added" <<E;
        return task;
    }
    else {
        return z;
    }
}




Task* TaskDeleter(Task tasks[], int choosed) {
    for (size_t i = 0; i < SS; i++)
    {
        if (i >= choosed) {
            tasks[i] = tasks[i + 1];
        }
    }
    CL
    S CO "Task deleted" << E;
    return tasks;
}







void TasksShower(Task task, int i) {
    S CO i << "\t" << task.prior << '\t' << task.time.day << '\\' << task.time.month << '\\' << task.time.year << "\t" << task.time.hour << ':' << task.time.min << '\t' << task.name << E;
}

Task TaskEditor(Task task) {
    bool choise = 1;
    Task z = task;
    task = TaskEdit(task);
    CL
    TaskShow(task);
    S CO E << "Add changes to list?\n1 - Yes\t0 - No\n";
    S cin >> choise;
    CL
    if (choise) {
        S CO "Task edited" << E;
        return task;
    }
    else {
        return z;
    }
}






Task* TaskSelected(Task tasks[], int i) {
    CL
    TaskShow(tasks[i]);
    int choose;
    
    S CO "What action:\n1 - Edit task\t2 - Delete task\t0 - End work" << E;
    S cin >> choose;
    switch (choose)
    {
    case 1: {
        tasks[i] = TaskEditor(tasks[i]);
        return tasks;
        break;
    }
    case 2: {
        TaskDeleter(tasks, i);
        return tasks;
        break;
    }
    default:
        return tasks;
        break;
    }
}







void quickSortP(Task* tasks, int N) {
    long i = 0, j = N - 1;
    Task temp, p;
    p = tasks[N >> 1];
    do {
        while (tasks[i].prior < p.prior) i++;
        while (tasks[j].prior > p.prior) j--;

        if (i <= j) {
            temp = tasks[i]; tasks[i] = tasks[j]; tasks[i] = temp;
            i++; j--;
        }
    } while (i <= j);

    if (j > 0) quickSortP(tasks, j);
    if (N > i) quickSortP(tasks + i, N - i);


}



void TaskSearch(Task tasks[]) {
    S CO "Search by:\n1 - name\t2 - description\t3 - priority\t4 - date" << E;
    int choose;
    S cin >> choose;
    switch (choose)
    {
    case 1: {
        
        char search[5], comp[5];
        S cin >> search;
        CL
        SH
        for (size_t i = 0; i < SS; i++)
        {
            for (size_t j = 0; j < 5; j++)
            {
                comp[j] = tasks[i].name[j];
            }
            if (strcmp(comp, search) == 0) {
                TasksShower(tasks[i], i);
            }
        }
        S CO "Choose task: ";
        S cin >> choose;
        TaskSelected(tasks, choose);
        break;
    }
    case 2: {
        char search[5], comp[5];
        S cin >> search;
        CL
        SH
        for (size_t i = 0; i < SS; i++)
        {
            for (size_t j = 0; j < 5; j++)
            {
                comp[j] = tasks[i].descript[j];
            }
            if (strcmp(comp, search) == 0) {
                TasksShower(tasks[i], i);
            }
        }
        S CO "Choose task: ";
        S cin >> choose;
        TaskSelected(tasks, choose);
        break;
    }
    case 3: {
        int cmp;
        S CO E << "Enter proirity: ";
        S cin >> cmp;
        CL
        SH
        for (size_t i = 0; i < SS; i++)
        {
            if (cmp == tasks[i].prior) {
                TasksShower(tasks[i], i);
            }
        }
        S CO "Choose task: ";
        S cin >> choose;
        TaskSelected(tasks, choose);
        break;
    }
    case 4: {
        int date[5];
        S CO "Enter date:" << E;
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
        CL
        SH
        for (size_t i = 0; i < SS; i++)
        {
            if (date[0] == tasks[i].time.year && date[1] == tasks[i].time.month && date[2] == tasks[i].time.day && date[3] == tasks[i].time.hour && date[4] == tasks[i].time.min) {
                TasksShower(tasks[i], i);
            }
        }
        S CO "Choose task: ";
        S cin >> choose;
        TaskSelected(tasks, choose);
    }
    default:
        break;
    }

}





void TaskMenu(Task tasks[], Time current) {
    S CO "Enter action:\n1 - Choose task\t2 - Show tasks by time\t3 - Search tasks\t0 - Exit programm" << E;
    int choise, sel;
    S cin >> choise;
    switch (choise)
    {
    case 1: {
        S CO "Choose task: ";
        S cin >> choise;
        TaskSelected(tasks, choise);
        break;
    }
    case 2: {
        S CO "Choose time:\n1 - For day\t2 - For week\t3 - For month\n";
        S cin >> choise;
        CL
            switch (choise)
            {
            case 1: {
                SH
                    for (size_t i = 0; i < SS; i++)
                    {
                        if (current.year == tasks[i].time.year && current.month == tasks[i].time.month && current.day == tasks[i].time.day) {

                            TasksShower(tasks[i], i);
                        }
                    }
                sel = 1;
                S CO "Choose action\n1 - Choose task\t2 - Sort list by priority" << E;
                S cin >> choise;
                switch (choise)
                {
                case 1: {
                    S CO "Choose task: ";
                    S cin >> choise;
                    TaskSelected(tasks, choise);
                    break;
                }
                case 2: {
                    quickSortP(tasks, SS);
                    if (sel == 1) {
                        for (size_t i = 0; i < SS; i++)
                        {
                            if (current.year == tasks[i].time.year && current.month == tasks[i].time.month && current.day == tasks[i].time.day) {

                                TasksShower(tasks[i], i);
                            }
                        }
                    }
                    break;
                }
                default:
                    break;
                }
                break;
            }
            case 2: {
                SH
                    for (size_t i = 0; i < SS; i++)
                    {
                        if (current.year == tasks[i].time.year && current.month == tasks[i].time.month && current.day == tasks[i].time.day) {

                            TasksShower(tasks[i], i);
                        }
                    }
                sel = 2;
                S CO "Choose action\n1 - Choose task\t2 - Sort list by priority" << E;
                S cin >> choise;
                switch (choise)
                {
                case 1: {
                    S CO "Choose task: ";
                    S cin >> choise;
                    TaskSelected(tasks, choise);
                    break;
                }
                case 2: {
                    quickSortP(tasks, SS);
                    if (sel == 2) {
                        for (size_t i = 0; i < SS; i++)
                        {
                            if (current.year == tasks[i].time.year && current.month == tasks[i].time.month && tasks[i].time.day - current.day <= 7) {

                                TasksShower(tasks[i], i);
                            }
                        }
                    }
                    break;
                }
                default:
                    break;
                }
                break;
            }
            case 3: {
                SH
                    for (size_t i = 0; i < SS; i++)
                    {
                        if (current.year == tasks[i].time.year && current.month == tasks[i].time.month) {

                            TasksShower(tasks[i], i);
                        }
                    }
                sel = 3;
                S CO "Choose action\n1 - Choose task\t2 - Sort list by priority" << E;
                S cin >> choise;
                switch (choise)
                {
                case 1: {
                    S CO "Choose task: ";
                    S cin >> choise;
                    TaskSelected(tasks, choise);
                    break;
                }
                case 2: {
                    quickSortP(tasks, SS);
                    if (sel == 2) {
                        for (size_t i = 0; i < SS; i++)
                        {
                            if (current.year == tasks[i].time.year && current.month == tasks[i].time.month) {

                                TasksShower(tasks[i], i);
                            }
                        }
                    }
                    break;
                }
                default:
                    break;
                }
                break;
            }
            }
            break;
    }
    case 3: {
        TaskSearch(tasks);
        break;
    }
    default:
        exit(0);
        break;
    }
}




int main()
{
    setlocale(LC_ALL, "");
    Task* tasks = new Task[SS];
    Time current;
    S CO "Enter curent date:" << E;
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

    for (size_t i = 0; i < SS; i++)
    {
        if (tasks[i].prior < 0) {
            tasks[i].prior = 0;
            tasks[i].time.year = 0;
            tasks[i].time.month = 0;
            tasks[i].time.day = 0;
            tasks[i].time.hour = 0;
            tasks[i].time.min = 0;
        }
    }
    while (1) {
        S CO "id" << '\t' << "Prior" << '\t' << "Date" << '\t' << "Time" << '\t' << "Name" << E;
        for (size_t i = 0; i < SS; i++)
        {
            TasksShower(tasks[i], i);
        }
        TaskMenu(tasks, current);
    }
    
}

