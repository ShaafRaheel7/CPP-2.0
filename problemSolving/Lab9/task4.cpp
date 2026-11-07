#include <iostream>
#include <string>
using namespace std;

struct Person {
    string name;
    int interactionScore;
    Person *close, *acquaintance;
    Person(string n, int s) : name(n), interactionScore(s), close(nullptr), acquaintance(nullptr) {}
};

void findSecondDegree(Person* root) {
    if (!root) return;
    Person* queue[100];
    int levels[100];
    int head = 0, tail = 0;

    queue[tail] = root;
    levels[tail++] = 0;

    cout << "2nd Degree Connections (Friends of Friends):" << endl;
    while (head < tail) {
        Person* curr = queue[head];
        int level = levels[head++];

        if (level == 2) cout << "- " << curr->name << endl;
        if (level < 2) {
            if (curr->close) {
                queue[tail] = curr->close;
                levels[tail++] = level + 1;
            }
            if (curr->acquaintance) {
                queue[tail] = curr->acquaintance;
                levels[tail++] = level + 1;
            }
        }
    }
}

int main() {
    Person* alice = new Person("shaaf", 100);
    alice->close = new Person("Taha", 80);
    alice->acquaintance = new Person("Moiz", 40);
    
    alice->close->close = new Person("Momin", 90);
    alice->close->acquaintance = new Person("Manan", 50);
    alice->acquaintance->close = new Person("Mateen", 70);

    findSecondDegree(alice);

    return 0;
}