#include <iostream>
using namespace std;

#define MAX 10

int adjMatrix[MAX][MAX];
int vertices = 0;

void addVertex() {
    vertices++;
}

void addEdge(int from, int to) {
    adjMatrix[from][to] = 1;
}

void displayMatrix() {
    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++)
            cout << adjMatrix[i][j] << " ";
        cout << endl;
    }
}

int countEdgesMatrix() {
    int count = 0;
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            if (adjMatrix[i][j] == 1)
                count++;
    return count;
}

int main() {
    addVertex(); 
    addVertex(); 
    addVertex(); 

    addEdge(0, 1);
    addEdge(1, 2);
    addEdge(0, 2);

    displayMatrix();
    cout << "Total edges: " << countEdgesMatrix();
    return 0;
}
