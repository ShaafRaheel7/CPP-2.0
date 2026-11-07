#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class CircularLinkedList {
public:
    Node* head;

    CircularLinkedList() {
        head = NULL;
    }

    void insertEnd(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            return;
        }

        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
    }

    void insertHead(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            return;
        }

        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    void deleteAtHead() {
        if (head == NULL) return;
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        Node* toDelete = head;

        if (temp == head) {
            head = NULL;
            delete toDelete;
            return;
        }
        temp->next = head->next;
        head = head->next;
        delete toDelete;
    }
    void deleteAtPosition(int pos) {
        if (pos == 1) {
            deleteAtHead();
            return;
        }
        Node* temp = head;
        int count = 1;

        while (count != pos - 1 && temp->next != head) {
            temp = temp->next;
            count++;
        }
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        cout << "Circular Linked List: ";

        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        cout << endl;
    }
};

int main() {
    CircularLinkedList cll;

    int n, value,pos;

    cout << "How many nodes you want to enter? ";
    cin >> n;

    cout << "Enter values:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        cll.insertEnd(value);
    }

    cout << "\nOriginal List:\n";
    cll.display();

    cout << "\nEnter value to insert at head: ";
    cin >> value;

    cll.insertHead(value);

    cout << "\nUpdated List:\n";
    cll.display();
    cout << "Enter value to delete: ";
    cin >> pos;
    cll.deleteAtPosition(pos);
    cll.display();
    return 0;
}
