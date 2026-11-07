#include <iostream>
using namespace std;
#define size 20   

class Queue {
    int arr[size];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isFull() { return rear == size - 1; }

    bool isEmpty() { return (front == -1 || front > rear); }

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
            return -1;
        }
        int val = arr[front++];
        if (front > rear) front = rear = -1; 
        return val;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty!\n";
            return;
        }
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    void interleave() {
        if (isEmpty()) return;

        int total = rear - front + 1;
        if (total % 2 != 0) {
            cout << "Queue must have even number of elements!\n";
            return;
        }

        int half = total / 2;

        int temp[half];
        for (int i = 0; i < half; i++) {
            temp[i] = dequeue();
        }

        for (int i = 0; i < half; i++) {
            enqueue(temp[i]);      // first half element
            enqueue(dequeue());    // second half element
        }
    }
};

int main() {
    Queue q;
    int n, x;

    cout << "Enter even number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> x;
        q.enqueue(x);
    }

    cout << "\nOriginal Queue: ";
    q.display();

    q.interleave();

    cout << "Interleaved Queue: ";
    q.display();

    return 0;
}
