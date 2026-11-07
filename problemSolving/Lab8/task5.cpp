#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* root = NULL;


void inorder(Node* r) {
    if (r == NULL)
        return;
    inorder(r->left);
    cout << r->data << " ";
    inorder(r->right);
}

void preorder(Node* r) {
    if (r == NULL)
        return;
    cout << r->data << " ";
    preorder(r->left);
    preorder(r->right);
}

void postorder(Node* r) {
    if (r == NULL)
        return;
    postorder(r->left);
    postorder(r->right);
    cout << r->data << " ";
}


Node* searchNode(Node* r, int key) {
    if (r == NULL)
        return NULL;
    if (r->data == key)
        return r;

    Node* leftSearch = searchNode(r->left, key);
    if (leftSearch != NULL)
        return leftSearch;

    return searchNode(r->right, key);
}

void addRoot() {
    if (root != NULL) {
        cout << "Root already exists\n";
        return;
    }
    int val;
    cout << "Enter root value: ";
    cin >> val;
    root = new Node(val);
}

void addLeftChild() {
    int parent, val;
    cout << "Enter parent value: ";
    cin >> parent;

    Node* p = searchNode(root, parent);
    if (p == NULL) {
        cout << "Parent not found\n";
        return;
    }
    if (p->left != NULL) {
        cout << "Left child already exists\n";
        return;
    }
    cout << "Enter left child value: ";
    cin >> val;
    p->left = new Node(val);
}

void addRightChild() {
    int parent, val;
    cout << "Enter parent value: ";
    cin >> parent;

    Node* p = searchNode(root, parent);
    if (p == NULL) {
        cout << "Parent not found\n";
        return;
    }
    if (p->right != NULL) {
        cout << "Right child already exists\n";
        return;
    }
    cout << "Enter right child value: ";
    cin >> val;
    p->right = new Node(val);
}

int main() {
    int choice;

    do {
        cout << "\n--- Binary Tree Menu ---\n";
        cout << "1. Create Root\n";
        cout << "2. Add Left Child\n";
        cout << "3. Add Right Child\n";
        cout << "4. Inorder Traversal\n";
        cout << "5. Preorder Traversal\n";
        cout << "6. Postorder Traversal\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addRoot(); break;
            case 2: addLeftChild(); break;
            case 3: addRightChild(); break;
            case 4:
                cout << "Inorder: ";
                inorder(root);
                cout << endl;
                break;
            case 5:
                cout << "Preorder: ";
                preorder(root);
                cout << endl;
                break;
            case 6:
                cout << "Postorder: ";
                postorder(root);
                cout << endl;
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid Choice\n";
        }

    } while (choice != 7);

    return 0;
}
