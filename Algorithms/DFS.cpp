#include <iostream>
#include <vector>

using namespace std;

void DFS(int u, vector<vector<int>> &adj, vector<bool> &visited)
{
    // Mark current vertex as visited
    visited[u] = true;

    // Print current vertex
    cout << u << " ";

    // Visit all adjacent vertices
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            DFS(v, adj, visited);
        }
    }
}

int main()
{
    int vertices, edges;

    cout << "Enter the number of vertices: ";
    cin >> vertices;

    cout << "Enter the number of edges: ";
    cin >> edges;

    vector<vector<int>> adj(vertices);

    cout << "Enter the edges (u v):" << endl;

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;

        // Undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start;

    cout << "Enter the starting vertex for DFS: ";
    cin >> start;

    vector<bool> visited(vertices, false);

    cout << "Depth First Traversal: ";

    DFS(start, adj, visited);

    cout << endl;

    return 0;
}