#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int V, E;
    cin >> V >> E;

    // Adjacency list: {neighbor, weight}
    vector<vector<pair<int, int>>> graph(V);

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].push_back({v, w});
        graph[v].push_back({u, w}); // Remove this line for directed graphs
    }

    int source;
    cin >> source;

    // Distance array
    vector<int> distance(V, INT_MAX);

    // Min Heap: {distance, node}
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    distance[source] = 0;
    pq.push({0, source});

    while (!pq.empty())
    {
        int currentDistance = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();

        // Ignore outdated entries
        if (currentDistance > distance[currentNode])
            continue;

        for (auto neighbor : graph[currentNode])
        {
            int nextNode = neighbor.first;
            int weight = neighbor.second;

            if (distance[currentNode] + weight < distance[nextNode])
            {
                distance[nextNode] = distance[currentNode] + weight;
                pq.push({distance[nextNode], nextNode});
            }
        }g
    }

    cout << "Shortest Distance from Source:\n";

    for (int i = 0; i < V; i++)
    {
        cout << i << " -> " << distance[i] << endl;
    }

    return 0;
}