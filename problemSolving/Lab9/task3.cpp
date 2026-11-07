#include <iostream>
#include <string>
using namespace std;

struct ExpNode {
    string val;
    ExpNode *left, *right;
    ExpNode(string v) : val(v), left(nullptr), right(nullptr) {}
};

// Post-order
int evaluate(ExpNode* root) {
    if (!root->left && !root->right) return stoi(root->val);
    int L = evaluate(root->left);
    int R = evaluate(root->right);
    if (root->val == "+") return L + R;
    if (root->val == "*") return L * R;
    return 0;
}

// In-order
void printInfix(ExpNode* root) {
    if (!root) return;
    if (root->left) cout << "(";
    printInfix(root->left);
    cout << root->val;
    printInfix(root->right);
    if (root->right) cout << ")";
}

int main() {

    ExpNode* root = new ExpNode("*");
    root->left = new ExpNode("+");
    root->left->left = new ExpNode("3");
    root->left->right = new ExpNode("4");
    root->right = new ExpNode("5");

    cout << "Infix Notation: ";
    printInfix(root);
    cout << "\nEvaluation Result: " << evaluate(root) << endl;

    return 0;
}