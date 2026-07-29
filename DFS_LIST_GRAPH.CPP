#include <iostream>
#include <vector>
using namespace std;

void dfs(int node,
         vector<vector<int>>& adj,
         vector<bool>& visited,
         vector<int>& ans)
{
    visited[node] = true;

    ans.push_back(node);

    for (int neighbor : adj[node]) {

        if (!visited[neighbor]) {

            dfs(neighbor, adj, visited, ans);

        }
    }
}

int main() {

    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(V);

    for (int i = 0; i < E; i++) {

        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(V, false);
    vector<int> ans;

    dfs(0, adj, visited, ans);

    for (int x : ans)
        cout << x << " ";
}