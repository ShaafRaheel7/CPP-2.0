#include <iostream>
using namespace std;

class Node {
public:
    string name;
    string service;
    Node* next;

    Node(string n, string s) {
        name = n;
        service = s;
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

    void enqueue(string name, string service) {
        Node* newNode = new Node(name, service);

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << name << " added to the queue for " << service << ".\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "No customers in the queue.\n";
            return;
        }

        Node* temp = front;
        cout << "Serving: " << temp->name << " (" << temp->service << ")\n";

        front = front->next;
        delete temp;

        if (front == NULL)
            rear = NULL;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "\nCustomers Waiting in Queue:\n";
        Node* temp = front;
        while (temp != NULL) {
            cout << "- " << temp->name << " (" << temp->service << ")\n";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue bankQueue;
    int choice;
    string name, service;

    do {
        cout << "\n--- BANK QUEUE MANAGEMENT ---\n";
        cout << "1. Add Customer to Queue\n";
        cout << "2. Serve Customer\n";
        cout << "3. Display Queue\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Customer Name: ";
            cin >> name;
            cout << "Enter Service (Deposit/Withdrawal/Inquiry): ";
            cin >> service;
            bankQueue.enqueue(name, service);
            break;

        case 2:
            bankQueue.dequeue();
            break;

        case 3:
            bankQueue.display();
            break;

        case 4:
            cout << "Exiting... Thank you!\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
