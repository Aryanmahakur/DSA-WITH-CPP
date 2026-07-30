#include <iostream>
#include <vector>
#include <queue>
using namespace std;

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
        graph[v].push_back(u);   // Remove this line for directed graph
    }

    int source;
    cin >> source;

    vector<int> distance(V, -1);

    queue<int> q;

    q.push(source);
    distance[source] = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int neighbor : graph[node])
        {
            if (distance[neighbor] == -1)
            {
                distance[neighbor] = distance[node] + 1;
                q.push(neighbor);
            }
        }
    }

    cout << "Shortest Distance from " << source << endl;

    for (int i = 0; i < V; i++)
        cout << i << " : " << distance[i] << endl;
}