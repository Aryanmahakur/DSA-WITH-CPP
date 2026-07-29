#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bfsList(int V, vector<vector<int>>& adj, int start) {

    vector<int> ans;
    vector<bool> visited(V, false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {

        int node = q.front();
        q.pop();

        ans.push_back(node);

        for (int neighbor : adj[node]) {

            if (!visited[neighbor]) {

                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    return ans;
}

int main() {

    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(V);

    for (int i = 0; i < E; i++) {

        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);      // Remove for directed graph
    }

    vector<int> ans = bfsList(V, adj, 0);

    for (int x : ans)
        cout << x << " ";
}