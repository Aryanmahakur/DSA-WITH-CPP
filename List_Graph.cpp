#include <iostream>
#include <vector>
using namespace std;

int main() {

    int V = 4;

    vector<vector<int>> adj(V);

    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[0].push_back(2);
    adj[2].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[1].push_back(3);
    adj[3].push_back(1);
    //    for (int i = 0; i < E; i++) {

    //     int u, v;
    //     cin >> u >> v;

    //     adj[u].push_back(v);
    //     adj[v].push_back(u);   // Remove this line for directed graph
    // }

    for(int i=0;i<V;i++){

        cout<<i<<" -> ";

        for(auto x : adj[i])
            cout<<x<<" ";

        cout<<endl;
    }
}