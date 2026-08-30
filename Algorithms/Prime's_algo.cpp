#include <iostream>
#include <climits>
using namespace std;

void Prim(int n, int graph[10][10]) {

    int parent[10];
    int key[10];
    bool mstSet[10];

    // Initialize
    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    // Start from vertex 0
    key[0] = 0;
    parent[0] = -1;

    // Find MST
    for (int count = 0; count < n - 1; count++) {

        // Find vertex with minimum key
        int minKey = INT_MAX;
        int minIndex = -1;

        for (int v = 0; v < n; v++) {

            if (!mstSet[v] && key[v] < minKey) {
                minKey = key[v];
                minIndex = v;
            }
        }

        // Add vertex to MST
        mstSet[minIndex] = true;

        // Update adjacent vertices
        for (int v = 0; v < n; v++) {

            if (graph[minIndex][v] != 0 &&
                !mstSet[v] &&
                graph[minIndex][v] < key[v]) {

                parent[v] = minIndex;
                key[v] = graph[minIndex][v];
            }
        }
    }

    // Print MST
    cout << "\nEdge\tWeight\n";

    int total = 0;

    for (int i = 1; i < n; i++) {

        cout << parent[i]
             << " - "
             << i
             << "\t"
             << graph[i][parent[i]]
             << endl;

        total += graph[i][parent[i]];
    }

    cout << "\nTotal MST Weight = " << total << endl;
}

int main() {

    int n;
    int graph[10][10];

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    Prim(n, graph);

    return 0;
}