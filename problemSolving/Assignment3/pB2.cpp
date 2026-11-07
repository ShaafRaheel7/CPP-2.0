#include <iostream>
using namespace std;

int graph[10][10], visited[10];
int n = 5;

void dfs(int v) {
    cout << v << " ";
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[v][i] && !visited[i])
            dfs(i);
    }
}

int main() {
    graph[0][1] = graph[0][2] = 1;
    graph[1][3] = 1;
    graph[2][4] = 1;

    cout << "DFS Traversal: ";
    dfs(0);
    return 0;
}
