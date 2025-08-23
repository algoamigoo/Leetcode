class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};

        // build adjacency list
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // helper BFS to get farthest node + parent tracking
        auto bfs = [&](int start) {
            vector<int> dist(n, -1), parent(n, -1);
            queue<int> q;
            q.push(start);
            dist[start] = 0;
            int farthest = start;

            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v : adj[u]) {
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        parent[v] = u;
                        q.push(v);
                        if (dist[v] > dist[farthest]) farthest = v;
                    }
                }
            }
            return pair<int, vector<int>>(farthest, parent);
        };

        // step 1: from any node, get farthest u
        auto [u, _] = bfs(0);
        // step 2: from u, get farthest v + parent tracking
        auto [v, parent] = bfs(u);

        // step 3: recover diameter path u -> v
        vector<int> path;
        for (int x = v; x != -1; x = parent[x])
            path.push_back(x);

        int m = path.size();
        if (m % 2 == 1) {
            return { path[m/2] };
        } else {
            return { path[m/2], path[m/2 - 1] };
        }
    }
};
