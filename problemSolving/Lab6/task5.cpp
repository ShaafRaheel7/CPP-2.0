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
            cout << "Stack overflow\n";
            return;
        }
        arr[++top] = x;
    }

    char pop() {
        if (top == -1) {
            return '\0';
        }
        return arr[top--];
    }

    char peek() {
        if (top == -1) return '\0';
        return arr[top];
    }

    bool empty() {
        return top == -1;
    }
};

int prec(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

bool isOperator(char c) {
    return (c=='+' || c=='-' || c=='*' || c=='/' || c=='^');
}

string infixToPostfix(string infix) {
    Stack st;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];
        if (isalnum(c)) {
            postfix += c;
        }
        else if (c == '(') {
            st.push(c);
        }
        else if (c == ')') {
            while (!st.empty() && st.peek() != '(') {
                postfix += st.pop();
            }
            st.pop();
        }
        else if (isOperator(c)) {
            while (!st.empty() && prec(st.peek()) >= prec(c)) {
                postfix += st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        postfix += st.pop();
    }
    return postfix;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    cout << "Postfix expression: " 
         << infixToPostfix(infix) << endl;

    return 0;
}
