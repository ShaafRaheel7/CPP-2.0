#include <iostream>
using namespace std;

struct Product {
    int id;
    float price;
    Product *left, *right;
    Product(int i, float p) : id(i), price(p), left(nullptr), right(nullptr) {}
};

Product* insertProduct(Product* root, int id, float price) {
    if (!root) return new Product(id, price);
    if (price < root->price) root->left = insertProduct(root->left, id, price);
    else root->right = insertProduct(root->right, id, price);
    return root;
}

// Find Min/Max Price
void findMinMax(Product* root) {
    if (!root) return;
    Product *min = root, *max = root;
    while (min->left) min = min->left;
    while (max->right) max = max->right;
    cout << "Cheapest: $" << min->price << " | Most Expensive: $" << max->price << endl;
}

int main() {
    Product* stock = nullptr;
    stock = insertProduct(stock, 1, 19.99);
    stock = insertProduct(stock, 2, 5.50);
    stock = insertProduct(stock, 3, 50.00);
    stock = insertProduct(stock, 4, 25.00);

    findMinMax(stock);
    return 0;
}