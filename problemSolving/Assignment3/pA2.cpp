#include <iostream>
using namespace std;

struct Node {
    int vertex;
    Node* next;
};

Node* adjList[10];
int vCount = 0;

void addVertex() {
    adjList[vCount] = NULL;
    vCount++;
}

void addEdge(int from, int to) {
    Node* newNode = new Node;
    newNode->vertex = to;
    newNode->next = adjList[from];
    adjList[from] = newNode;
}

void displayList() {
    cout << "Adjacency List:\n";
    for (int i = 0; i < vCount; i++) {
        cout << i << " -> ";
        Node* temp = adjList[i];
        while (temp != NULL) {
            cout << temp->vertex << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int countEdgesList() {
    int count = 0;
    for (int i = 0; i < vCount; i++) {
        Node* temp = adjList[i];
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
    }
    return count;
}

int main() {
    addVertex();
    addVertex();
    addVertex();

    addEdge(0, 1);
    addEdge(1, 2);
    addEdge(0, 2);

    displayList();
    cout << "Total edges: " << countEdgesList();
    return 0;
}
