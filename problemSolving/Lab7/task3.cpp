#include <iostream>
using namespace std;

struct Task {
    int id;
    Task* next;
};

Task* current = NULL;

void addTask() {
    int id;
    cout << "Enter Task ID: ";
    cin >> id;

    Task* t = new Task;
    t->id = id;

    if (!current) {
        current = t;
        t->next = t;
    } else {
        t->next = current->next;
        current->next = t;
    }
}

void executeTask() {
    if (!current) {
        cout << "No Tasks\n";
        return;
    }

    cout << "Executing Task " << current->id << endl;
    current = current->next;
}

void displayCurrent() {
    if (!current) {
        cout << "No Tasks\n";
        return;
    }
    cout << "Current Task: " << current->id << endl;
}

int main() {
    int choice;
    do {
        cout << "\n--- Task Scheduler ---\n";
        cout << "1. Add Task\n";
        cout << "2. Execute Task\n";
        cout << "3. Show Current Task\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addTask(); break;
            case 2: executeTask(); break;
            case 3: displayCurrent(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid Choice\n";
        }
    } while (choice != 4);

    return 0;
}
