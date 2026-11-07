#include <iostream>
#include <string>
using namespace std;

string undoStack[20], redoStack[20];
int undoTop = -1, redoTop = -1;

void perform(string action) {
    undoStack[++undoTop] = action;
    redoTop = -1;
}

void undo() {
    if (undoTop >= 0) {
        redoStack[++redoTop] = undoStack[undoTop--];
        cout << "Undo\n";
    }
}

void redo() {
    if (redoTop >= 0) {
        undoStack[++undoTop] = redoStack[redoTop--];
        cout << "Redo\n";
    }
}

void clearHistory() {
    undoTop = redoTop = -1;
}

int main() {
    perform("Draw Circle");
    perform("Fill Color");

    undo();
    redo();
    clearHistory();

    return 0;
}
