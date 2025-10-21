//  Anynode which is not a parentnode but which is visited then we can say that cycle has been detected.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to detect cycle in an undirected graph using DFS
    bool dfs(int node, vector<int> adj[], vector<int>& visited, int parent) {
        visited[node] = 1;

        for (int nbr : adj[node]) {
            if (!visited[nbr]) {
                if (dfs(nbr, adj, visited, node)) {
                    return true; // cycle found in DFS subtree
                }
            } else if (nbr != parent) {
                return true; // cycle found (back edge to a non-parent)
            }
        }
        return false;
    }

    // Function to check if a cycle exists in the graph
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> visited(V, 0);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(i, adj, visited, -1)) {
                    return true; // cycle detected
                }
            }
        }
        return false; // no cycle
    }
};
