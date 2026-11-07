#include <iostream>
#include <string>
using namespace std;

int value(char c) {
    if (c == 'I') return 1;
    if (c == 'V') return 5;
    if (c == 'X') return 10;
    if (c == 'L') return 50;
    if (c == 'C') return 100;
    if (c == 'D') return 500;
    if (c == 'M') return 1000;
    return 0;
}
int main() {
    string s;
    cout << "Enter Roman numeral: ";
    cin >> s;
    int total = 0;

    for (int i = 0; i < s.length(); i++) {
        if (i + 1 < s.length() && value(s[i]) < value(s[i + 1])) {
            total -= value(s[i]);
        } else {
            total += value(s[i]);
        }
    }
    cout << "Integer value: " << total << endl;
    return 0;
}
