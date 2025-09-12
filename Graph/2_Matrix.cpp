#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> adjacencymatrix)
{
    for (int i = 1; i < adjacencymatrix.size(); i++)
    {
        cout << "Node " << i << " is connected to: ";
        for (int j = 1; j < adjacencymatrix[i].size(); j++)
        {
            if(adjacencymatrix[i][j] == 1)
            {cout << j << " ";}
        }
        cout << endl;
    }

    // Create linked list
}

int main()
{

    vector<vector<int>> edgelist = {
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 2},
        {1, 3}};
    int n = 5;
    vector<vector<int>> adjacencymatrix(5, vector<int>(5, 0));
    for (int i = 0; i < edgelist.size(); i++)
    {
        int u = edgelist[i][0];
        int v = edgelist[i][1];
        adjacencymatrix[u][v] = 1;
        adjacencymatrix[v][u] = 1; // for undirected graph
    }
    solve(adjacencymatrix);

    return 0;
}
