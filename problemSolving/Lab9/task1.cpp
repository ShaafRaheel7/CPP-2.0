#include <iostream>
#include <string>
using namespace std;

struct CategoryNode {
    string categoryName;
    int productCount;
    CategoryNode *leftChild, *rightChild;

    CategoryNode(string name, int count) {
        categoryName = name;
        productCount = count;
        leftChild = rightChild = nullptr;
    }
};

// Pre-order
void displayHierarchy(CategoryNode* root, int depth) {
    if (!root) return;
    for (int i = 0; i < depth; i++) cout << "  ";
    cout << "- " << root->categoryName << " (" << root->productCount << ")" << endl;
    displayHierarchy(root->leftChild, depth + 1);
    displayHierarchy(root->rightChild, depth);
}

// Post-order
int calculateSubtreeProducts(CategoryNode* root) {
    if (!root) return 0;
    return root->productCount + calculateSubtreeProducts(root->leftChild);
}

int main() {
    
    CategoryNode* root = new CategoryNode("Electronics", 0);
    root->leftChild = new CategoryNode("Mobile Phones", 10);
    root->leftChild->leftChild = new CategoryNode("Smartphones", 50);
    root->leftChild->leftChild->rightChild = new CategoryNode("Feature Phones", 20);
    
    root->leftChild->rightChild = new CategoryNode("Computers", 5);
    root->leftChild->rightChild->leftChild = new CategoryNode("Laptops", 30);
    
    cout << "Store Hierarchy Structure:" << endl;
    displayHierarchy(root, 0);

    cout << "\nTotal products in Mobile Phones & Subcategories: " 
         << calculateSubtreeProducts(root->leftChild) << endl;

    return 0;
}