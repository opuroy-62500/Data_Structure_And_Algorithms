#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

void Dijkstra(int n, vector<vector<pair<int, int>>> &graph,
              int source, int destination)
{
    vector<int> dist(n, INT_MAX);
    vector<int> pred(n, -1);

    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> Q;

    dist[source] = 0;
    Q.push({0, source});

    while (!Q.empty())
    {
        int u = Q.top().second;
        Q.pop();

        for (auto edge : graph[u])
        {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                pred[v] = u;
                Q.push({dist[v], v});
            }
        }
    }

    // No path exists
    if (dist[destination] == INT_MAX)
    {
        cout << "No path exists." << endl;
        return;
    }

    // Construct shortest path
    vector<int> path;

    for (int v = destination; v != -1; v = pred[v])
        path.push_back(v);

    reverse(path.begin(), path.end());

    cout << "Shortest Path: ";

    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i];

        if (i != path.size() - 1)
            cout << " -> ";
    }

    cout << "\nShortest Distance: " << dist[destination] << endl;
}

int main()
{
    int n, e;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    vector<vector<pair<int, int>>> graph(n);

    cout << "Enter edges (u v weight):\n";

    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].push_back({v, w});
    }

    int source, destination;

    cout << "Enter source: ";
    cin >> source;

    cout << "Enter destination: ";
    cin >> destination;

    Dijkstra(n, graph, source, destination);

    return 0;
}