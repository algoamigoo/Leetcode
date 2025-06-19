class Solution {
public:
    vector<int> minimumWeight(vector<vector<int>> &edges, vector<vector<int>> &queries) {
        int n = edges.size() + 1, q = queries.size();

        vector<vector<pair<int, int>>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].emplace_back(e[1], e[2]);
            adj[e[1]].emplace_back(e[0], e[2]);
        }

        int maxPower = log2(n);
        vector<int> depths(n), cumulativeWeight(n);
        vector<vector<int>> up(n, vector<int>(maxPower + 1, -1));

        dfs(0, -1, 0, 0, depths, cumulativeWeight, adj, up);
        preprocess(n, maxPower, up);

        vector<int> result(q);
        for (int i = 0; i < q; ++i) {
            int a = queries[i][0], b = queries[i][1], c = queries[i][2];
            int total = (dist(a, c, maxPower, depths, cumulativeWeight, up) +
                         dist(b, c, maxPower, depths, cumulativeWeight, up) +
                         dist(a, b, maxPower, depths, cumulativeWeight, up)) / 2;
            result[i] = total;
        }

        return result;
    }

    void dfs(int node, int parent, int depth, int accWeight,
             vector<int> &depths, vector<int> &cumulativeWeight,
             vector<vector<pair<int, int>>> &adj, vector<vector<int>> &up) {
        depths[node] = depth;
        cumulativeWeight[node] = accWeight;
        up[node][0] = parent;

        for (auto &[neighbor, weight] : adj[node]) {
            if (neighbor != parent) {
                dfs(neighbor, node, depth + 1, accWeight + weight, depths, cumulativeWeight, adj, up);
            }
        }
    }

    void preprocess(int n, int maxPower, vector<vector<int>> &up) {
        for (int p = 1; p <= maxPower; ++p) {
            for (int node = 0; node < n; ++node) {
                int par = up[node][p - 1];
                if (par != -1) {
                    up[node][p] = up[par][p - 1];
                }
            }
        }
    }

    int lift(int u, int diff, const vector<vector<int>> &up) {
        while (diff > 0) {
            int step = log2(diff);
            u = up[u][step];
            diff -= (1 << step);
        }
        return u;
    }

    int lca(int u, int v, int maxPower, const vector<int> &depths, const vector<vector<int>> &up) {
        if (depths[u] > depths[v]) swap(u, v);
        v = lift(v, depths[v] - depths[u], up);

        if (u == v) return u;

        for (int i = maxPower; i >= 0; --i) {
            if (up[u][i] != -1 && up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }

    int dist(int u, int v, int maxPower, const vector<int> &depths,
             const vector<int> &cumulativeWeight, const vector<vector<int>> &up) {
        int common = lca(u, v, maxPower, depths, up);
        return cumulativeWeight[u] + cumulativeWeight[v] - 2 * cumulativeWeight[common];
    }
};
