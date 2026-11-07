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
private:
    Node* head;

public:
    CircularLinkedList() {
        head = NULL;
    }
    void insert(int val) {
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
    void display() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        cout << endl;
    }

    void reverseList() {
    if (head == NULL || head->next == head) {
        return;
    }

    Node* prev = NULL;
    Node* current = head;
    Node* nextNode;

    do {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    } 
    while (current != head);
    head->next = prev;
    head = prev;
}

};
int main() {
    CircularLinkedList cll;

    int n, value;
    cout << "How many nodes you want to enter? ";
    cin >> n;
    cout << "Enter values:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        cll.insert(value);
    }
    cout << endl;
    cll.display();
    cout << "Reversing list..."<<endl;
    cll.reverseList();
    cout << "Reversed list: "; cll.display();
    return 0;
}
