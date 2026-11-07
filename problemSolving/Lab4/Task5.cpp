#include <iostream>
using namespace std;

class Node {
public:
    int jobID;
    int priority; 
    Node* next;

    Node(int id, int p) {
        jobID = id;
        priority = p;
        next = NULL;
    }
};
class PrintQueue {
    Node* front;

public:
    PrintQueue() {
        front = NULL;
    }

    bool isEmpty() {
        return (front == NULL);
    }

    void enqueue(int id, int priority) {
        Node* newNode = new Node(id, priority);

        if (isEmpty() || priority < front->priority) {
            newNode->next = front;
            front = newNode;
        } 
        else {
            Node* temp = front;
            while (temp->next != NULL && temp->next->priority <= priority) {
                temp = temp->next;
            }

            newNode->next = temp->next;
            temp->next = newNode;
        }

        cout << "Job " << id << " added with priority " 
             << priority << ".\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "No print jobs in the queue.\n";
            return;
        }

        Node* temp = front;
        cout << "Processing Job ID: " << temp->jobID 
             << " (Priority " << temp->priority << ")\n";

        front = front->next;
        delete temp;
    }

    void display() {
        if (isEmpty()) {
            cout << "Print queue is empty.\n";
            return;
        }

        cout << "\nPrint Jobs in Queue:\n";
        Node* temp = front;
        while (temp != NULL) {
            cout << "- Job ID " << temp->jobID 
                 << " | Priority: " << temp->priority << "\n";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    PrintQueue pq;
    int choice, id, priority;

    do {
        cout << "\n--- PRINT SERVER MENU ---\n";
        cout << "1. Add Print Job\n";
        cout << "2. Process Next Job\n";
        cout << "3. Display Queue\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Job ID: ";
            cin >> id;
            cout << "Enter Priority (1=High, 2=Medium, 3=Low): ";
            cin >> priority;
            pq.enqueue(id, priority);
            break;

        case 2:
            pq.dequeue();
            break;

        case 3:
            pq.display();
            break;

        case 4:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
