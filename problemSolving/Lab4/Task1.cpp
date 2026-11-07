#include <iostream>
using namespace std;
#define size 5

class Queue {
    int item[size];
    int front, rear;
public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (rear == size - 1);
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue is Full!\n";
            return;
        }
        if (front == -1)  
            front = 0;
        rear++;
        item[rear] = val;
        cout << val << " Inserted Successfully!\n";
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty!\n";
            return;
        }
        cout << item[front] << " Deleted Successfully!\n";
        front++;
        if (front > rear) {
            front = rear = -1;
        }
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty!\n";
            return;
        }
        cout << "Front index: " << front << endl;
        cout << "Items in Queue: ";
        for (int i = front; i <= rear; i++) {
            cout << item[i] << " ";
        }
        cout << endl << "Rear index: " << rear << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6); 

    q.display();

    q.dequeue();
    q.display();

    return 0;
}
