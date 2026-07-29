#include <iostream>
#include <vector>
using namespace std;

void dfs(int node,
         vector<vector<int>>& matrix,
         vector<bool>& visited,
         vector<int>& ans)
{
    visited[node] = true;

    ans.push_back(node);

    // Check every column in the row
    for (int i = 0; i < matrix.size(); i++) {

        if (matrix[node][i] == 1 && !visited[i]) {

            dfs(i, matrix, visited, ans);

        }
    }
}

int main() {

    int V, E;
    cin >> V >> E;

    vector<vector<int>> matrix(V, vector<int>(V, 0));

    for (int i = 0; i < E; i++) {

        int u, v;
        cin >> u >> v;

        matrix[u][v] = 1;
        matrix[v][u] = 1;      // Remove for directed graph
    }

    vector<bool> visited(V, false);
    vector<int> ans;

    dfs(0, matrix, visited, ans);

    for (int x : ans)
        cout << x << " ";
}