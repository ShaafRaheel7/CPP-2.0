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

    void searchValue(int val) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    int position = 1;

    do {
        if (temp->data == val) {
            cout << "Value " << val << " found at position " << position << ".\n";
            return;
        }
        temp = temp->next;
        position++;
    } 
    while (temp != head);

    cout << "Value " << val << " not found in the list.\n";
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
    int valueToSearch;
    cout << "\nEnter value to search: ";
    cin >> valueToSearch;

    cll.searchValue(valueToSearch);

    return 0;
}
