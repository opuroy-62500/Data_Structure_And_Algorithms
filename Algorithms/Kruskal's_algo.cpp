#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
    int u, v, weight;
};

// Find the parent of a vertex
int findParent(int parent[], int v)
{
    if (parent[v] == v)
        return v;

    return parent[v] = findParent(parent, parent[v]);
}

// Union two sets
void unionSets(int parent[], int u, int v)
{
    int rootU = findParent(parent, u);
    int rootV = findParent(parent, v);

    if (rootU != rootV)
    {
        parent[rootV] = rootU;
    }
}

void Kruskal(int n, int graph[10][10])
{
    int parent[10];

    // Initialize parent
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    vector<Edge> edges;

    // Store all edges
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (graph[i][j] != 0)
            {
                edges.push_back({i, j, graph[i][j]});
            }
        }
    }

    // Sort edges by weight
    sort(edges.begin(), edges.end(),
         [](Edge a, Edge b)
         {
             return a.weight < b.weight;
         });

    cout << "\nEdge\tWeight\n";

    int totalWeight = 0;
    int edgeCount = 0;

    // Kruskal's algorithm
    for (const auto &edge : edges)
    {
        if (findParent(parent, edge.u) !=
            findParent(parent, edge.v))
        {
            cout << edge.u << " - "
                 << edge.v << "\t"
                 << edge.weight << endl;

            totalWeight += edge.weight;
            edgeCount++;

            unionSets(parent, edge.u, edge.v);

            // MST has n-1 edges
            if (edgeCount == n - 1)
                break;
        }
    }

    cout << "\nMinimum Cost = " << totalWeight << endl;
}

int main()
{
    int n;

    cout << "Enter the number of vertices: ";
    cin >> n;

    int graph[10][10];

    cout << "Enter the adjacency matrix:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    Kruskal(n, graph);

    return 0;
}
