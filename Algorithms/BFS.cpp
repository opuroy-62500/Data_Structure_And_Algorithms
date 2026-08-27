#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(int start, int vertices, vector<vector<int>> &adj)
{
    vector<bool> visited(vertices, false);

    queue<int> q;

    // Mark starting vertex as visited
    visited[start] = true;

    // Insert starting vertex into queue
    q.push(start);

    while (!q.empty())
    {
        // Remove front vertex
        int u = q.front();
        q.pop();

        // Print the vertex
        cout << u << " ";

        // Visit all adjacent vertices
        for (int v : adj[u])
        {
            if (!visited[v])
            {
                visited[v] = true;
                q.push(v);
            }
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

    cout << "Enter the starting vertex for BFS: ";
    cin >> start;

    cout << "Breadth First Traversal: ";

    BFS(start, vertices, adj);

    cout << endl;

    return 0;
}