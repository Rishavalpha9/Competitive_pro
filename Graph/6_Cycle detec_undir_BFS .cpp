#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to detect cycle in an undirected graph using BFS
    bool bfs(int node, vector<int> adj[], vector<int>& visited, vector<int>& parent) {
        queue<int> q;
        q.push(node);
        visited[node] = 1;

        while (!q.empty()) {
            int f = q.front();
            q.pop();

            for (int nbr : adj[f]) {
                if (!visited[nbr]) {
                    visited[nbr] = 1;
                    parent[nbr] = f;
                    q.push(nbr);
                }
                else { // visited[nbr] is true now
                    if (parent[f] != nbr) {
                        return true; // cycle found
                    }
                }
            }
        }
        return false;
    }

    bool isCycle(int V, vector<int> adj[]) {
        vector<int> visited(V, 0), parent(V, -1);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                bool ans = bfs(i, adj, visited, parent);
                if (ans == true) { // if found cycle for any component, return true
                    return true;
                }
            }
        }
        return false;
    }
};
