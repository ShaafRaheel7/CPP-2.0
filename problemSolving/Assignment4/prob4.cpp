#include <iostream>
using namespace std;

#define V 4
#define E 4
#define INF 9999

struct Edge {
    int src, dest, weight;
};

bool detectNegativeCycle(Edge edges[]) {
    int dist[V];

    for (int i = 0; i < V; i++)
        dist[i] = 0;

    for (int i = 1; i <= V; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int w = edges[j].weight;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                if (i == V)
                    return true;
            }
        }
    }
    return false;
}

int main() {
    Edge edges[E] = {
        {0,1,1},
        {1,2,-1},
        {2,3,-1},
        {3,0,-1}
    };

    if (detectNegativeCycle(edges))
        cout << "Negative Cycle Detected";
    else
        cout << "No Negative Cycle";

    return 0;
}
