// BY BFS

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        unordered_map<int, vector<int>> graph;
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<bool> visited(n, false);
        queue<int> q;
        q.push(source);
        visited[source] = true;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            if (node == destination) {
                return true;
            }
            for (auto& ed : graph[node]) {

                if (visited[ed] == 0) {
                    q.push(ed);
                    visited[ed] = true;
                }
            }
        }
        return false;
    }
};
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
// BY  DFS
class Solution {
public:
    bool check(int source, int destination, unordered_map<int, vector<int>>& graph,
               vector<bool>& visited) {

        if (source == destination)
            return true;
        if (visited[source])
            return false;

        visited[source] = true;

        for (auto &nbr : graph[source]) {
            if (check(nbr, destination, graph, visited)) {
                return true;
            }
        }

        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {

        unordered_map<int, vector<int>> graph;
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<bool> visited(n, false);
        return check(source, destination, graph, visited);
    }
};
