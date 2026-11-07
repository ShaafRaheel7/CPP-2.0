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

void deleteNode(Node* &head, int key) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    if (head->data == key) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        cout << "Node with value " << key << " deleted.\n";
        return;
    }
    Node* temp = head;
    while (temp->next != NULL && temp->next->data != key) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        cout << "Key not found in the list.\n";
        return;
    }

    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;

    cout << "Node with value " << key << " deleted.\n";
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
    int n, value, key;

    cout << "How many nodes do you want to insert? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value: ";
        cin >> value;
        insertAtEnd(head, value);
    }

    cout << "\nEnter key to delete: ";
    cin >> key;

    deleteNode(head, key);

    cout << endl;
    display(head);

    return 0;
}
