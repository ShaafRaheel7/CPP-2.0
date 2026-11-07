#include <iostream>
#include <string>
using namespace std;

bool used[10];

bool checkMatch(string s, int start, string words[],
                int wordCount, int wordLen) {

    for (int i = 0; i < wordCount; i++)
        used[i] = false;

    for (int i = 0; i < wordCount; i++) {
        string part = s.substr(start + i * wordLen, wordLen);
        bool found = false;

        for (int j = 0; j < wordCount; j++) {
            if (!used[j] && words[j] == part) {
                used[j] = true;
                found = true;
                break;
            }
        }

        if (!found) return false;
    }
    return true;
}

int main() {
    string s = "barfoothefoobarman";
    string words[] = {"foo", "bar"};

    int wordCount = 2;
    int wordLen = words[0].length();
    int totalLen = wordCount * wordLen;

    cout << "Starting indices: ";

    for (int i = 0; i + totalLen <= s.length(); i++) {
        if (checkMatch(s, i, words, wordCount, wordLen))
            cout << i << " ";
    }
    return 0;
}
