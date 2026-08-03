#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 4;

    vector<vector<int>> dist(n, vector<int>(n, 1e9));

    for (int i = 0; i < n; i++)
        dist[i][i] = 0;

    vector<vector<int>> edges = {
        {0,1,5},
        {1,2,2},
        {0,2,10},
        {2,3,1}
    };

    for (auto &e : edges) {
        int u = e[0];
        int v = e[1];
        int w = e[2];

        dist[u][v] = w;
    }

    for (int via = 0; via < n; via++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (dist[i][via] != 1e9 &&
                    dist[via][j] != 1e9) {

                    dist[i][j] = min(dist[i][j],
                                     dist[i][via] + dist[via][j]);
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == 1e9)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}