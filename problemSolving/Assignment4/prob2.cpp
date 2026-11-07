#include <iostream>
using namespace std;

#define INF 9999
#define V 6

int minDist(int dist[], bool visited[]) {
    int min = INF, idx;
    for (int i = 0; i < V; i++)
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            idx = i;
        }
    return idx;
}

int dijkstra(int graph[V][V], int src, int dest) {
    int dist[V];
    bool visited[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = false;
    }

    dist[src] = 0;

    for (int i = 0; i < V - 1; i++) {
        int u = minDist(dist, visited);
        visited[u] = true;

        for (int v = 0; v < V; v++)
            if (graph[u][v] && !visited[v] &&
                dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    return dist[dest];
}

int main() {
    int graph[V][V] = {
        {0, 4, 0, 0, 0, 0},
        {4, 0, 8, 0, 0, 0},
        {0, 8, 0, 7, 2, 4},
        {0, 0, 7, 0, 9, 14},
        {0, 0, 2, 9, 0, 10},
        {0, 0, 4, 14, 10, 0}
    };

    cout << "Shortest distance from 0 to 4: "
         << dijkstra(graph, 0, 4);
    return 0;
}
