#include<iostream>
using namespace std;

void BellmanFord(int graph[10][10], int n, int start) {
    int dist[10];

    // Initialize distances from start to all vertices as infinite
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
    }
    dist[start] = 0;

    // Relax edges repeatedly
    for (int i = 1; i <= n - 1; i++) {
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if (graph[u][v] != 0 && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }

    // Check for negative-weight cycles
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0 && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                cout << "Graph contains negative weight cycle" << endl;
                return;
            }
        }
    }

    // Print the distance array
    cout << "Vertex Distance from Source" << endl;
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX) {
            cout << i << "\t\t" << "INF" << endl;
        } else {
            cout << i << "\t\t" << dist[i] << endl;
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    int graph[10][10];
    cout << "Enter the adjacency matrix (enter 0 for no edge):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    int start;
    cout << "Enter the starting vertex: ";
    cin >> start;

    BellmanFord(graph, n, start);

    return 0;
}