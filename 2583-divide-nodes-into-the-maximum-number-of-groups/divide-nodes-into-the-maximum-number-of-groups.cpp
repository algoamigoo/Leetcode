#include <bits/stdc++.h>
using namespace std;

// graph must be bipartite, since when 2 vertices are connect by an edge
// they need to be in different groups, if odd length cycle then not possible
// make a triangle and see

// we will do bfs from each vertex and see the max distance from that vertex
// answer will be max of all those distances

// what if there are disconnected components?
// simply add the answer for different components

bool isBipartite(unordered_map<int, vector<int>> &adj, int node, vector<int> &colors, int currcolor) {
    colors[node] = currcolor;
    for (auto ngbr : adj[node]) {
        if (colors[ngbr] == -1) {
            if (!isBipartite(adj, ngbr, colors, 1 - currcolor)) {
                return false;
            }
        } else if (colors[ngbr] == colors[node]) {
            return false;
        }
    }
    return true;
}

int bfs(unordered_map<int, vector<int>> &adj, int node, int n) {
    vector<bool> visited(n, false);
    queue<int> q;
    int levels = 0;
    q.push(node);
    visited[node] = true;
    
    while (!q.empty()) {
        int size = q.size();
        levels++;
        while (size--) {
            int x = q.front();
            q.pop();
            for (auto it : adj[x]) {
                if (!visited[it]) {
                    visited[it] = true;
                    q.push(it);
                }
            }
        }
    }
    return levels;
}

class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        // create and populate graph
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0] - 1;
            int v = edges[i][1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // bipartite check
        vector<int> colors(n, -1);
        for (int i = 0; i < n; i++) {
            if (colors[i] == -1) {
                if (!isBipartite(adj, i, colors, 1)) {
                    return -1;
                }
            }
        }

        // finding max of each bfs (basically max no of levels from each node)
        vector<int> maxLevels(n, 0);
        for (int i = 0; i < n; i++) {
            maxLevels[i] = bfs(adj, i, n);
        }

        // if they are same component, make the value equal to the max one
        // for all vertices of that component
        // now for each different component add
        unordered_set<int> visited;
        int result = 0;
        for (int i = 0; i < n; i++) {
            if (visited.count(i)) continue;
            queue<int> q;
            q.push(i);
            int componentMax = 0;
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                visited.insert(node);
                componentMax = max(componentMax, maxLevels[node]);
                for (auto &ngbr : adj[node]) {
                    if (!visited.count(ngbr)) {
                        q.push(ngbr);
                    }
                }
            }
            result += componentMax;
        }

        return result;
    }
};
