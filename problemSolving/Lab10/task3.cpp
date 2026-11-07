#include <iostream>
#include <string>
using namespace std;

struct WordNode {
    string word;
    string definition;
    WordNode *left, *right;
    WordNode(string w, string d) : word(w), definition(d), left(nullptr), right(nullptr) {}
};

WordNode* addWord(WordNode* root, string w, string d) {
    if (!root) return new WordNode(w, d);
    if (w < root->word) root->left = addWord(root->left, w, d);
    else if (w > root->word) root->right = addWord(root->right, w, d);
    return root;
}

// Search for exact word
void findWord(WordNode* root, string w) {
    if (!root) { cout << "Not found." << endl; return; }
    if (root->word == w) cout << w << ": " << root->definition << endl;
    else if (w < root->word) findWord(root->left, w);
    else findWord(root->right, w);
}

int main() {
    WordNode* dict = nullptr;
    dict = addWord(dict, "Apple", "A fruit");
    dict = addWord(dict, "Binary", "Base-2 number system");
    dict = addWord(dict, "C++", "A programming language");

    cout << "Search result for 'Binary': ";
    findWord(dict, "Binary");
    return 0;
}