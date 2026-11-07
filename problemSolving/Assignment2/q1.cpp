#include <iostream>
using namespace std;

struct Call {
    int id;
    int priority;
    int waitTime;
};

Call queue[20];
int front = 0, rear = -1;

void insertCall(Call c) {
    rear++;
    queue[rear] = c;
}

void emergencyOverride(Call c) {
    for (int i = rear; i >= front; i--)
        queue[i + 1] = queue[i];
    queue[front] = c;
    rear++;
}

int getNextCall() {
    int best = front;
    for (int i = front + 1; i <= rear; i++) {
        if (queue[i].priority < queue[best].priority)
            best = i;
    }
    return best;
}

void dispatch() {
    if (front > rear) {
        cout << "No calls\n";
        return;
    }
    int idx = getNextCall();
    cout << "Dispatching Call ID: " << queue[idx].id << endl;

    for (int i = idx; i < rear; i++)
        queue[i] = queue[i + 1];
    rear--;
}

int main() {
    insertCall({1, 2, 5});
    insertCall({2, 3, 2});
    insertCall({3, 1, 1});   // Priority 1

    emergencyOverride({99, 1, 0});

    dispatch();
    dispatch();
    return 0;
}
