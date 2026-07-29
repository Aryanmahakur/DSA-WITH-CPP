#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bfsMatrix(int V, vector<vector<int>>& matrix, int start) {

    vector<int> ans;
    vector<bool> visited(V, false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {

        int node = q.front();
        q.pop();

        ans.push_back(node);

        // Traverse the entire row
        for (int i = 0; i < V; i++) {

            if (matrix[node][i] == 1 && !visited[i]) {

                visited[i] = true;
                q.push(i);
            }
        }
    }

    return ans;
}

int main() {

    int V, E;
    cin >> V >> E;

    vector<vector<int>> matrix(V, vector<int>(V, 0));

    for (int i = 0; i < E; i++) {

        int u, v;
        cin >> u >> v;

        matrix[u][v] = 1;
        matrix[v][u] = 1;     // Remove for directed graph
    }

    vector<int> ans = bfsMatrix(V, matrix, 0);

    for (int x : ans)
        cout << x << " ";
}