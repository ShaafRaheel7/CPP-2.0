#include <iostream>
using namespace std;

int graph[10][10], visited[10];
int n = 5;

void bfs(int start) {
    int queue[10], front = 0, rear = 0;

    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        int v = queue[front++];
        cout << v << " ";

        for (int i = 0; i < n; i++) {
            if (graph[v][i] && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    graph[0][1] = graph[0][2] = 1;
    graph[1][3] = 1;
    graph[2][4] = 1;

    cout << "BFS Traversal: ";
    bfs(0);
    return 0;
}
