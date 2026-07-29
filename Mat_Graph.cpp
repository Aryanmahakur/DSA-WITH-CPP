#include <iostream>
#include <vector>
using namespace std;

int main() {

    int V = 4;

    vector<vector<int>> matrix(V, vector<int>(V,0));

    matrix[0][1]=1;
    matrix[1][0]=1;

    matrix[0][2]=1;
    matrix[2][0]=1;

    matrix[1][2]=1;
    matrix[2][1]=1;

    matrix[1][3]=1;
    matrix[3][1]=1;
//    for (int i = 0; i < E; i++) {

//         int u, v;
//         cin >> u >> v;

//         matrix[u][v] = 1;
//         matrix[v][u] = 1;   // Remove this line for directed graph
//     }
    for(auto row : matrix){
        for(auto x : row)
            cout<<x<<" ";
        cout<<endl;
    }
}