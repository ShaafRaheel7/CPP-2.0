#include <iostream>
using namespace std;

class Node {
public:
    string taskName;
    bool needsResource;
    Node* next;

    Node(string name, bool resource) {
        taskName = name;
        needsResource = resource;
        next = NULL;
    }
};

class Queue {
    Node* front;
    Node* rear;

public:
    Queue() {
        front = NULL;
        rear = NULL;
    }

    bool isEmpty() {
        return (front == NULL);
    }

    void enqueue(string name, bool resource) {
        Node* newNode = new Node(name, resource);

        if (isEmpty()) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Task \"" << name << "\" added to queue.\n";
    }

    Node* dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return NULL;
        }

        Node* temp = front;
        front = front->next;

        if (front == NULL)
            rear = NULL;

        return temp;
    }

    void display(string title) {
        cout << "\n--- " << title << " ---\n";
        if (isEmpty()) {
            cout << "No tasks.\n";
            return;
        }

        Node* temp = front;
        while (temp != NULL) {
            cout << "- " << temp->taskName;
            if (temp->needsResource)
                cout << " (Needs Resource)";
            cout << endl;
            temp = temp->next;
        }
    }
};

int main() {
    Queue taskQueue;     // Ready tasks
    Queue waitingQueue;  // Tasks waiting for resource

    int choice;
    string name;
    int needsRes;

    bool resourceAvailable = true;

    do {
        cout << "\n===== OS TASK SCHEDULER =====\n";
        cout << "1. Add Task\n";
        cout << "2. Process Next Task\n";
        cout << "3. Free Resource & Move Waiting Tasks\n";
        cout << "4. Display Queues\n";
        cout << "5. Toggle Resource Availability\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter Task Name: ";
            cin >> name;
            cout << "Does it need a resource? (1=Yes, 0=No): ";
            cin >> needsRes;
            taskQueue.enqueue(name, needsRes);
            break;

        case 2: {
            Node* task = taskQueue.dequeue();
            if (task == NULL) break;

            if (task->needsResource && !resourceAvailable) {
                cout << "Resource unavailable! Moving task \"" 
                     << task->taskName << "\" to waiting queue.\n";
                waitingQueue.enqueue(task->taskName, task->needsResource);
            } 
            else {
                cout << "Processing task: " << task->taskName << endl;
            }

            delete task;
            break;
        }

        case 3:
            cout << "Freeing resource and moving waiting tasks...\n";
            resourceAvailable = true;
            while (!waitingQueue.isEmpty()) {
                Node* t = waitingQueue.dequeue();
                taskQueue.enqueue(t->taskName, t->needsResource);
                delete t;
            }
            break;

        case 4:
            taskQueue.display("Main Task Queue");
            waitingQueue.display("Waiting Queue");
            break;

        case 5:
            resourceAvailable = !resourceAvailable;
            cout << "Resource is now: " 
                 << (resourceAvailable ? "AVAILABLE" : "UNAVAILABLE")
                 << endl;
            break;

        case 6:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 6);

    return 0;
}
