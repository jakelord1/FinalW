#include <iostream>
#define S std::
#define CO cout << 
#define T Task.
#define SI Size
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
struct Task {
    char name[50];
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
Task TaskAdd(Task task) {
    S CO "Task Adding" << E;

    S CO "Enter name of task(до 50 символов): ";
    S cin.getline(task.name, 50);

    S CO "Enter task description(до 250 символов): ";
    S cin.getline(task.descript, SI);

    S CO "Enter priority of task(1 - 4): ";
    S cin >> task.prior;

    S CO "Enter date of task:";
    S CO E << "Year: ";
    S cin >> task.time.year;
    S CO E << "Month: ";
    S cin >> task.time.month;
    S CO E << "Day: ";
    S cin >> task.time.day;
    S CO E << "Hours: ";
    S cin >> task.time.hour;
    S CO E << "Minutes: ";
    S cin >> task.time.min;
    return task;
}
Task TaskAdder(Task task) {
    bool choise = 1;
    do {
        task = TaskAdd(task);
        TaskShow(task);
        S CO E << "Add task to list?\n0 - Yes\t1 - No(Recreate)\n";
        S cin >> choise;
    } while (0);
    //system("cls");
    S CO "Task added";
    return task;
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

//Task TaskEditor(Task task) {
//
//}
void TaskSearch(Task tasks) {

}
void TasksShower(Task tasks) {

}
void TaskSort() {

}
int main()
{
    setlocale(LC_ALL, "");
    Task* tasks = new Task[5];
    TaskAdder(tasks[0]);
}

