#include <iostream>
#include <vector>
using namespace std;

struct Task {
    string description;
    bool completed;
};

vector<Task> taskList;

void addTask() {
    string taskDesc;
    cout << "Enter task description: ";
    cin.ignore();
    getline(cin, taskDesc);

    taskList.push_back({taskDesc, false});
    cout << "Task added successfully.\n";
}

void viewTasks() {
    if (taskList.empty()) {
        cout << "No tasks available.\n";
        return;
    }

    cout << "\n--- To-Do List ---\n";
    for (size_t i = 0; i < taskList.size(); ++i) {
        cout << i + 1 << ". [" << (taskList[i].completed ? "X" : " ") << "] " 
             << taskList[i].description << "\n";
    }
    cout << endl;
}

void markTaskCompleted() {
    int index;
    viewTasks();
    if (taskList.empty()) return;

    cout << "Enter the task number to mark as completed: ";
    cin >> index;

    if (index < 1 || index > taskList.size()) {
        cout << "Invalid task number.\n";
    } else {
        taskList[index - 1].completed = true;
        cout << "Task marked as completed.\n";
    }
}

void removeTask() {
    int index;
    viewTasks();
    if (taskList.empty()) return;

    cout << "Enter the task number to remove: ";
    cin >> index;

    if (index < 1 || index > taskList.size()) {
        cout << "Invalid task number.\n";
    } else {
        taskList.erase(taskList.begin() + index - 1);
        cout << "Task removed successfully.\n";
    }
}

void showMenu() {
    cout << "\n--- TO-DO LIST MENU ---\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Remove Task\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1: addTask(); break;
            case 2: viewTasks(); break;
            case 3: markTaskCompleted(); break;
            case 4: removeTask(); break;
            case 5: cout << "Exiting To-Do List Manager.\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}

