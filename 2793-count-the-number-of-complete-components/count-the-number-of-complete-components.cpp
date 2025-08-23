class Solution {
public:
    void dfs(int u, const vector<vector<int>>& adj, vector<int>& vis, long long& nodes, long long& degSum) {
        vis[u] = 1;
        nodes++;
        degSum += adj[u].size();
        for (int v : adj[u]) if (!vis[v]) dfs(v, adj, vis, nodes, degSum);
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<int> vis(n, 0);
        int ans = 0;

        for (int i = 0; i < n; i++) if (!vis[i]) {
            long long nodes = 0, degSum = 0;
            dfs(i, adj, vis, nodes, degSum);
            long long E = degSum / 2;
            long long need = nodes * (nodes - 1) / 2; 
            if (E == need) ans++;
        }
        return ans;
    }
};
