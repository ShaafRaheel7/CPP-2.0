#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Stack {
    Node* top;  

public:
    Stack() {
        top = NULL;
    }
    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = top;  
        top = newNode;        
        cout << x << " pushed\n";
    }

    void pop() {
        if (top == NULL) {
            cout << "Stack underflow\n";
            return;
        }
        cout << top->data << " popped\n";
        Node* temp = top;
        top = top->next;
        delete temp;    
    }

    bool isEmpty() {
        return top == NULL;
    }

    void display() {
        if (top == NULL) {
            cout << "Stack is empty\n";
            return;
        }

        cout << "Stack elements: ";
        Node* temp = top;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);

    st.display();

    st.pop();
    st.display();

    return 0;
}
