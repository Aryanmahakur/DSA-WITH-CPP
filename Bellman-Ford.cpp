#include <bits/stdc++.h>
using namespace std;

vector<int> bellmanFord(int V, vector<vector<int>> &edges, int src)
{
    vector<int> distance(V, INT_MAX);
    distance[src] = 0;

    // Relax all edges V-1 times
    for (int i = 0; i < V - 1; i++)
    {
        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];

            if (distance[u] != INT_MAX &&
                distance[u] + weight < distance[v])
            {
                distance[v] = distance[u] + weight;
            }
        }
    }

    // Check for negative weight cycle
    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int weight = edge[2];

        if (distance[u] != INT_MAX &&
            distance[u] + weight < distance[v])
        {
            cout << "Negative Weight Cycle Found\n";
            return {};
        }
    }

    return distance;
}

int main()
{
    int V = 5;

    vector<vector<int>> edges = {
        {0, 1, 6},
        {0, 2, 7},
        {1, 2, 8},
        {1, 3, 5},
        {1, 4, -4},
        {2, 3, -3},
        {2, 4, 9},
        {3, 1, -2},
        {4, 3, 7},
        {4, 0, 2}
    };

    vector<int> distance = bellmanFord(V, edges, 0);

    if (!distance.empty())
    {
        cout << "Shortest Distances:\n";
        for (int i = 0; i < V; i++)
        {
            cout << "0 -> " << i << " = ";

            if (distance[i] == INT_MAX)
                cout << "INF";
            else
                cout << distance[i];

            cout << endl;
        }
    }

    return 0;
}