#include<iostream>
#include<climits>
using namespace std;

void Dijkstra(int n, int graph[10][10], int start) {
    int dist[n];
    bool visited[n];

    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[start] = 0;

    for (int count = 0; count < n - 1; count++) {
        int minDist = INT_MAX, minIndex;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && dist[v] < minDist) {
                minDist = dist[v];
                minIndex = v;
            }
        }

        visited[minIndex] = true;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[minIndex][v] && dist[minIndex] != INT_MAX &&
                dist[minIndex] + graph[minIndex][v] < dist[v]) {
                dist[v] = dist[minIndex] + graph[minIndex][v];
            }
        }
    }

    cout << "Vertex \tDistance from Source\n";
    for (int i = 0; i < n; i++)
        cout << i << " \t" << dist[i] << endl;
}

int main() {
    int n, start;
    cout << "Enter the number of vertices: ";
    cin >> n;

    int graph[10][10];
    cout << "Enter the adjacency matrix (enter 0 for no edge):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    cout << "Enter the starting vertex: ";
    cin >> start;

    Dijkstra(n, graph, start);

    return 0;
}