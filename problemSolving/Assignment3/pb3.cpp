#include <iostream>
using namespace std;

int graph[10][10], visited[10], recStack[10];
int n = 4;

bool detectCycle(int v) {
    visited[v] = 1;
    recStack[v] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[v][i]) {
            if (!visited[i] && detectCycle(i))
                return true;
            else if (recStack[i])
                return true;
        }
    }

    recStack[v] = 0;
    return false;
}

int main() {
    graph[0][1] = 1;
    graph[1][2] = 1;
    graph[2][0] = 1; // cycle

    for (int i = 0; i < n; i++) {
        if (!visited[i] && detectCycle(i)) {
            cout << "Cycle Detected";
            return 0;
        }
    }

    cout << "No Cycle";
    return 0;
}
