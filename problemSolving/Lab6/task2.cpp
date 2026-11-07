#include <iostream>
#include <string>
using namespace std;
#define n 100

class Stack {
    char arr[n];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(char x) {
        if (top == n - 1) {
            cout << "Stack overflow" << endl;
            return;
        }
        arr[++top] = x;
    }

    void pop() {
        if (top == -1) {
            return;
        }
        top--;
    }

    char peek() {
        if (top == -1) return '\0';
        return arr[top];
    }

    bool empty() {
        return top == -1;
    }
};

bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool checkBalanced(string exp) {
    Stack st;

    for (char ch : exp) {
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (st.empty()) return false;
            char top = st.peek();
            if (!isMatching(top, ch)) return false;

            st.pop();
        }
    }
    return st.empty();
}

int main() {
    string expression;
    cout << "Enter expression: ";
    getline(cin, expression);

    if (checkBalanced(expression))
        cout << "Parentheses are balanced!" << endl;
    else
        cout << "Parentheses are NOT balanced!" << endl;

    return 0;
}
