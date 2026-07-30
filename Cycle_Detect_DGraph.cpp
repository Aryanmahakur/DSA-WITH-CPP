#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node,
         vector<vector<int>>& graph,
         vector<bool>& visited,
         vector<bool>& pathVisited)
{
    // Mark current node as visited
    visited[node] = true;
    pathVisited[node] = true;

    // Visit all neighbors
    for (int neighbor : graph[node])
    {
        // If neighbor is not visited
        if (!visited[neighbor])
        {
            if (dfs(neighbor, graph, visited, pathVisited))
                return true;
        }
        // If neighbor is already in the current DFS path
        else if (pathVisited[neighbor])
        {
            return true;
        }
    }

    // Remove current node from recursion stack
    pathVisited[node] = false;

    return false;
}

int main()
{
    int V, E;
    cin >> V >> E;

    vector<vector<int>> graph(V);

    // Input directed edges
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
    }

    vector<bool> visited(V, false);
    vector<bool> pathVisited(V, false);

    bool cycle = false;

    // Check every component
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (dfs(i, graph, visited, pathVisited))
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