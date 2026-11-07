#include <iostream>
using namespace std;

class Node {
public:
    string name;
    Node* next;

    Node(string n) {
        name = n;
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

    void enqueue(string name) {
        Node* newNode = new Node(name);

        if (isEmpty()) {
            front = rear = newNode;
        } 
        else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << name << " joined the line.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "No customers to serve.\n";
            return;
        }

        Node* temp = front;
        cout << "Serving customer: " << temp->name << endl;

        front = front->next;
        delete temp;

        if (front == NULL)
            rear = NULL;
    }

    int count() {
        int cnt = 0;
        Node* temp = front;
        while (temp != NULL) {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "\nCustomers currently waiting:\n";
        Node* temp = front;
        while (temp != NULL) {
            cout << "- " << temp->name << endl;
            temp = temp->next;
        }
    }

    void waitingTime() {
        int peopleAhead = count();
        const int serviceTime = 5; 

        cout << "\nPeople currently in line: " << peopleAhead << endl;
        cout << "Estimated waiting time: " 
             << peopleAhead * serviceTime 
             << " minutes.\n";
    }
};

int main() {
    Queue q;
    int choice;
    string name;

    do {
        cout << "\n--- CUSTOMER SERVICE CENTER ---\n";
        cout << "1. Add Customer to Line\n";
        cout << "2. Serve Next Customer\n";
        cout << "3. Display Queue\n";
        cout << "4. Check Estimated Waiting Time\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter customer name: ";
            cin >> name;
            q.enqueue(name);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.display();
            break;

        case 4:
            q.waitingTime();
            break;

        case 5:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
