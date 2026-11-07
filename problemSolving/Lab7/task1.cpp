#include <iostream>
using namespace std;

struct Post {
    int id;
    string text;
    bool pinned;
};

Post feed[100];
int countPosts = 0;

void addPost() {
    int id;
    string text;
    cout << "Enter Post ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter Post Text: ";
    getline(cin, text);

    for (int i = countPosts; i > 0; i--)
        feed[i] = feed[i - 1];

    feed[0] = {id, text, false};
    countPosts++;
}

void removePost() {
    int id;
    cout << "Enter Post ID to remove: ";
    cin >> id;

    for (int i = 0; i < countPosts; i++) {
        if (feed[i].id == id) {
            for (int j = i; j < countPosts - 1; j++)
                feed[j] = feed[j + 1];
            countPosts--;
            cout << "Post Removed\n";
            return;
        }
    }
    cout << "Post Not Found\n";
}

void pinPost() {
    int id;
    cout << "Enter Post ID to pin: ";
    cin >> id;

    for (int i = 0; i < countPosts; i++) {
        if (feed[i].id == id) {
            Post temp = feed[i];

            for (int j = i; j < countPosts - 1; j++)
                feed[j] = feed[j + 1];
            countPosts--;

            for (int j = countPosts; j > 0; j--)
                feed[j] = feed[j - 1];

            temp.pinned = true;
            feed[0] = temp;
            countPosts++;

            cout << "Post Pinned\n";
            return;
        }
    }
    cout << "Post Not Found\n";
}

void displayFeed() {
    if (countPosts == 0) {
        cout << "Feed Empty\n";
        return;
    }

    for (int i = 0; i < countPosts; i++) {
        cout << feed[i].id << " : " << feed[i].text;
        if (feed[i].pinned) cout << " (Pinned)";
        cout << endl;
    }
}

int main() {
    int choice;

    do {
        cout << "\n--- Social Media Feed ---\n";
        cout << "1. Add Post\n";
        cout << "2. Remove Post\n";
        cout << "3. Pin Post\n";
        cout << "4. Display Feed\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addPost(); break;
            case 2: removePost(); break;
            case 3: pinPost(); break;
            case 4: displayFeed(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid Choice\n";
        }
    } while (choice != 5);

    return 0;
}
