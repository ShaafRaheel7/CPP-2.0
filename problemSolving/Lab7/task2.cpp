#include <iostream>
using namespace std;

struct File {
    string name;
    File* next;
};

File* head = NULL;

void addFile() {
    string name;
    cout << "Enter file name: ";
    cin >> name;

    File* f = new File;
    f->name = name;
    f->next = head;
    head = f;
}

void listFiles() {
    if (!head) {
        cout << "Directory Empty\n";
        return;
    }

    File* temp = head;
    while (temp) {
        cout << temp->name << endl;
        temp = temp->next;
    }
}

void searchFile() {
    string name;
    cout << "Enter file name to search: ";
    cin >> name;

    File* temp = head;
    while (temp) {
        if (temp->name == name) {
            cout << "File Found\n";
            return;
        }
        temp = temp->next;
    }
    cout << "File Not Found\n";
}

int main() {
    int choice;
    do {
        cout << "\n--- File System ---\n";
        cout << "1. Add File\n";
        cout << "2. List Files\n";
        cout << "3. Search File\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addFile(); break;
            case 2: listFiles(); break;
            case 3: searchFile(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid Choice\n";
        }
    } while (choice != 4);

    return 0;
}
