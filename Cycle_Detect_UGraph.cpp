#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, int parent,
         vector<vector<int>>& graph,
         vector<bool>& visited)
{
    visited[node] = true;

    for (int neighbor : graph[node])
    {
        if (!visited[neighbor])
        {
            if (dfs(neighbor, node, graph, visited))
                return true;
        }
        else if (neighbor != parent)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    int V, E;
    cin >> V >> E;

    vector<vector<int>> graph(V);

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);    // Undirected edge
    }

    vector<bool> visited(V, false);

    bool cycle = false;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (dfs(i, -1, graph, visited))
            {
                cycle = true;
                break;
            }
        }
    }

    if (cycle)
        cout << "Cycle Found";
    else
        cout << "No Cycle";

    return 0;
}