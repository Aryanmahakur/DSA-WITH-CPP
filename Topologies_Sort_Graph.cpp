#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(int node,
         vector<vector<int>>& graph,
         vector<bool>& visited,
         stack<int>& st)
{
    visited[node] = true;

    for (int neighbor : graph[node])
    {
        if (!visited[neighbor])
            dfs(neighbor, graph, visited, st);
    }

    // Push after exploring all neighbors
    st.push(node);
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
    }

    vector<bool> visited(V, false);
    stack<int> st;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            dfs(i, graph, visited, st);
    }

    cout << "Topological Order: ";

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}