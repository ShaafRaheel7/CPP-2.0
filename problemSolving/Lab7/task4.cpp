#include <iostream>
using namespace std;

struct Item {
    string name;
    int qty;
    Item* prev;
    Item* next;
};

Item* head = NULL;

void addItem() {
    string name;
    int qty;

    cout << "Enter item name: ";
    cin >> name;
    cout << "Enter quantity: ";
    cin >> qty;

    Item* i = new Item;
    i->name = name;
    i->qty = qty;
    i->prev = NULL;
    i->next = head;

    if (head)
        head->prev = i;

    head = i;
}

void displayCart() {
    if (!head) {
        cout << "Cart Empty\n";
        return;
    }

    Item* temp = head;
    while (temp) {
        cout << temp->name << " x" << temp->qty << endl;
        temp = temp->next;
    }
}

int main() {
    int choice;
    do {
        cout << "\n--- Shopping Cart ---\n";
        cout << "1. Add Item\n";
        cout << "2. Display Cart\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addItem(); break;
            case 2: displayCart(); break;
            case 3: cout << "Exiting...\n"; break;
            default: cout << "Invalid Choice\n";
        }
    } while (choice != 3);

    return 0;
}
