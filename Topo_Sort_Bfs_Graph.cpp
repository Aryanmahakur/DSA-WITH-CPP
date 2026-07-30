#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int V, E;
    cin >> V >> E;

    vector<vector<int>> graph(V);
    vector<int> indegree(V, 0);

    // Build graph and calculate indegree
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;

    // Push all nodes with indegree 0
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    vector<int> topo;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        topo.push_back(node);

        for (int neighbor : graph[node])
        {
            indegree[neighbor]--;

            if (indegree[neighbor] == 0)
                q.push(neighbor);
        }
    }

    cout << "Topological Order: ";

    for (int node : topo)
        cout << node << " ";

    return 0;
}