#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void Kruskal(int n, int graph[10][10]) {
    int parent[n];
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    auto findParent = [&](int v) {
        if (parent[v] == v) return v;
        return parent[v] = findParent(parent[v]);
    };

    auto unionSets = [&](int u, int v) {
        int rootU = findParent(u);
        int rootV = findParent(v);
        if (rootU != rootV) {
            parent[rootV] = rootU;
        }
    };

    struct Edge {
        int u, v, weight;
    };

    vector<Edge> edges;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (graph[i][j] != 0) {
                edges.push_back({i, j, graph[i][j]});
            }
        }
    }

    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.weight < b.weight;
    });

    cout << "Edge \tWeight\n";
    for (const auto& edge : edges) {
        if (findParent(edge.u) != findParent(edge.v)) {
            cout << edge.u << " - " << edge.v << "\t" << edge.weight << endl;
            unionSets(edge.u, edge.v);
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

    Kruskal(n, graph);

    return 0;
}