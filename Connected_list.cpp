#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;

    for (int neighbor : graph[node]) {
        if (!visited[neighbor])
            dfs(neighbor, graph, visited);
    }
}

int connectedComponents(int V, vector<vector<int>>& graph) {
    vector<bool> visited(V, false);
    int count = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, graph, visited);
            count++;
        }
    }

    return count;
}

int main() {
    int V = 6;
    vector<vector<int>> graph(V);

    graph[0].push_back(1);
    graph[1].push_back(0);

    graph[2].push_back(3);
    graph[3].push_back(2);
    graph[3].push_back(4);
    graph[4].push_back(3);

    cout << "Connected Components = "
         << connectedComponents(V, graph);

    return 0;
}