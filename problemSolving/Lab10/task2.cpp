#include <iostream>
#include <string>
using namespace std;

struct Book {
    int isbn;
    string title;
    int height;
    Book *left, *right;

    Book(int i, string t) : isbn(i), title(t), height(1), left(nullptr), right(nullptr) {}
};

int getHeight(Book* n) { return n ? n->height : 0; }
int getBalance(Book* n) { return n ? getHeight(n->left) - getHeight(n->right) : 0; }

// Right Rotation
Book* rotateRight(Book* y) {
    Book* x = y->left;
    Book* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    return x;
}

// Left Rotation
Book* rotateLeft(Book* x) {
    Book* y = x->right;
    Book* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}

Book* insertBook(Book* node, int isbn, string title) {
    if (!node) return new Book(isbn, title);
    if (isbn < node->isbn) node->left = insertBook(node->left, isbn, title);
    else if (isbn > node->isbn) node->right = insertBook(node->right, isbn, title);
    else return node;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int balance = getBalance(node);

    // Balancing Logic
    if (balance > 1 && isbn < node->left->isbn) return rotateRight(node);
    if (balance < -1 && isbn > node->right->isbn) return rotateLeft(node);
    if (balance > 1 && isbn > node->left->isbn) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (balance < -1 && isbn < node->right->isbn) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    return node;
}

int main() {
    Book* root = nullptr;
    root = insertBook(root, 1001, "Data Structures");
    root = insertBook(root, 1005, "Algorithms");
    root = insertBook(root, 1002, "Operating Systems"); // This triggers a rotation

    cout << "Library AVL Tree (Root): " << root->title << " (ISBN: " << root->isbn << ")" << endl;
    return 0;
}