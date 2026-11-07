#include <iostream>
using namespace std;

#define V 5
#define E 8
#define INF 9999

struct Edge {
    int src, dest, weight;
};

void bellmanFord(Edge edges[], int src) {
    int dist[V];

    for (int i = 0; i < V; i++)
        dist[i] = INF;

    dist[src] = 0;

    for (int i = 1; i < V; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int w = edges[j].weight;

            if (dist[u] != INF && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    cout << "Vertex   Distance\n";
    for (int i = 0; i < V; i++)
        cout << i << " \t\t " << dist[i] << endl;
}

int main() {
    Edge edges[E] = {
        {0,1,-1},{0,2,4},{1,2,3},
        {1,3,2},{1,4,2},{3,2,5},
        {3,1,1},{4,3,-3}
    };

    bellmanFord(edges, 0);
    return 0;
}
