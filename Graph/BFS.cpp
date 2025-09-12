#include <bits/stdc++.h>
using namespace std;

void bfs(int source, unordered_map<int, vector<int>> &graph, int n) {
    queue<int> q;
    vector<int> visited(n, 0);

    q.push(source);
    visited[source] = 1;

    while (!q.empty()) {
        int f = q.front();
        q.pop();
        cout << f << " ";

        for (int nbr : graph[f]) {
            if (visited[nbr] == 0) {   // visit only unvisited neighbors
                visited[nbr] = 1;
                q.push(nbr);
            }
        }
    }
}

int main() {
    vector<vector<int>> edgeList = {
        {0, 1}, {1, 4}, {1, 2}, {2, 3}
    };

    int n = 5; // number of nodes
    unordered_map<int, vector<int>> graph;

    // Build adjacency list (undirected graph)
    for (int i = 0; i < edgeList.size(); i++) {
        int a = edgeList[i][0], b = edgeList[i][1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    cout << "BFS Order: ";
    bfs(0, graph, n);

    return 0;
}
