#include <iostream>
#include <string>
using namespace std;

struct Student {
    int studentId;
    string name;
    float gpa;
    Student *left, *right;

    Student(int id, string n, float g) : studentId(id), name(n), gpa(g), left(nullptr), right(nullptr) {}
};

Student* insert(Student* root, int id, string name, float gpa) {
    if (!root) return new Student(id, name, gpa);
    if (id < root->studentId) 
        root->left = insert(root->left, id, name, gpa);
    else if (id > root->studentId) 
        root->right = insert(root->right, id, name, gpa);
    return root;
}

void displaySorted(Student* root) {
    if (!root) return;
    displaySorted(root->left);
    cout << "ID: " << root->studentId << " | Name: " << root->name << " | GPA: " << root->gpa << endl;
    displaySorted(root->right);
}

int main() {
    Student* root = nullptr;
    root = insert(root, 105, "Shaaf", 3.8);
    root = insert(root, 102, "Taha", 3.5);
    root = insert(root, 110, "Momin", 3.9);

    cout << "Students sorted by ID:" << endl;
    displaySorted(root);
    return 0;
}