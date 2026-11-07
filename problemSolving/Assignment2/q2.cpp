#include <iostream>
#include <string>
using namespace std;

string backStack[20], forwardStack[20], closedTabs[10];
int backTop = -1, forwardTop = -1;
int closedFront = 0, closedRear = -1;

void openPage(string page) {
    backStack[++backTop] = page;
    forwardTop = -1;
}
void goBack() {
    if (backTop > 0) {
        forwardStack[++forwardTop] = backStack[backTop--];
        cout << "Back to " << backStack[backTop] << endl;
    }
}
void closeTab(string tab) {
    if (closedRear < 9)
        closedTabs[++closedRear] = tab;
}
int main() {
    openPage("Google");
    openPage("YouTube");
    openPage("GitHub");
    goBack();
    closeTab("GitHub");
    return 0;
}
