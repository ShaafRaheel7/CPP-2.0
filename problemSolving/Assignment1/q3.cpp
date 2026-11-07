#include <iostream>
#include <string>
using namespace std;

char keypad[10][5] = {
    "", "", "abc", "def", "ghi",
    "jkl", "mno", "pqrs", "tuv", "wxyz"
};

void generate(string digits, int index, char output[], int outIndex) {
    if (index == digits.length()) {
        output[outIndex] = '\0';
        cout << output << " ";
        return;
    }
    int digit = digits[index] - '0';

    for (int i = 0; keypad[digit][i] != '\0'; i++) {
        output[outIndex] = keypad[digit][i];
        generate(digits, index + 1, output, outIndex + 1);
    }}
int main() {
    string digits;
    cout << "Enter digits (2-9): ";
    cin >> digits;

    char output[20];
    generate(digits, 0, output, 0);
    return 0;
}
