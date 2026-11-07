#include <iostream>
using namespace std;

int regular[20], fast[20];
int rFront = 0, rRear = -1;
int fFront = 0, fRear = -1;
int regCount = 0;

void addRegular(int id) {
    regular[++rRear] = id;
}
void addFast(int id) {
    fast[++fRear] = id;
}
void emergency(int id) {
    for (int i = rRear; i >= rFront; i--)
        regular[i + 1] = regular[i];
    regular[rFront] = id;
    rRear++;
}
void process() {
    if (regCount == 3 && fFront <= fRear) {
        cout << "Processing Fast: " << fast[fFront++] << endl;
        regCount = 0;
    } else if (rFront <= rRear) {
        cout << "Processing Regular: " << regular[rFront++] << endl;
        regCount++; }}

int main() {
    addRegular(1);
    addRegular(2);
    addFast(100);
    addRegular(3);
    addRegular(4);
    for (int i = 0; i < 5; i++)
        process();
    return 0;
}
