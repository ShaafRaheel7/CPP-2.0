#include <iostream>
#include <string>
using namespace std;

#define n 100

class stack {
    char arr[n];
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
        cout << x << " pushed" << endl;
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
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    stack st;
    string str;
    cout << "Enter string to reverse: ";
    getline (cin,str);
    for (char c : str){
    st.push(c);
    }
    cout << "Reversed string :";
    st.display();

    return 0;
}
