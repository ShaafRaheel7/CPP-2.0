#include <iostream>
using namespace std;
#define size 5

class Queue {
    int arr[size];
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
        if (front == -1) front = 0;
        arr[++rear] = val;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty!\n";
            return -1;
        }
        int val = arr[front++];
        if (front > rear) 
            front = rear = -1;
        return val;
    }
    void reverse() {
        if (isEmpty())
            return;

        int x = dequeue();   
        reverse();             
        enqueue(x);            
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty!\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    cout << "Original: ";
    q.display();

    q.reverse();

    cout << "Reversed: ";
    q.display();

    return 0;
}
