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

void insertAtEnd(Node* &head, int val) {
    Node* n = new Node(val);

    if (head == NULL) {
        head = n;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = n;
}

void updateNode(Node* head, int oldValue, int newValue) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    while (temp != NULL && temp->data != oldValue) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Value " << oldValue << " not found in the list.\n";
    } else {
        temp->data = newValue;
        cout << "Node value updated from " << oldValue << " to " << newValue << ".\n";
    }
}

void display(Node* head) {
    cout << "Linked List: ";
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = NULL;
    int n, value, oldVal, newVal;

    cout << "How many nodes do you want to insert? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value: ";
        cin >> value;
        insertAtEnd(head, value);
    }

    cout << "\nEnter the value you want to update: ";
    cin >> oldVal;

    cout << "Enter the new value: ";
    cin >> newVal;

    updateNode(head, oldVal, newVal);

    cout << endl;
    display(head);

    return 0;
}
