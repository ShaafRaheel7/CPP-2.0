#include <iostream>
using namespace std;

#define n 100

class stack {
    int arr[n];
    int top;

public:
    stack() {
        top = -1;
    }

    void push(char x) {
        if (top == n - 1) {
            cout << "Stack overflow" << endl;
            return;
        }
        arr[++top] = x;
       // cout << x << " pushed" << endl;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack underflow" << endl;
            return;
        }
        cout << arr[top] << " popped" << endl;
        top--;
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    stack st;

    st.push(10);
    st.push(20);
    st.push(30);

    st.display();

    st.pop();
    st.display();

    st.pop();
    st.pop();
    st.pop();

    return 0;
}
