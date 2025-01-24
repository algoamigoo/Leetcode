class Solution {
public:
    class DSU {
        vector<int> parent, size;
    public:
        DSU(int n) {
            parent.resize(n);
            size.resize(n, 1);
            for (int i = 0; i < n; i++) parent[i] = i;
        }

        int find(int x) {
            return x == parent[x] ? x : parent[x] = find(parent[x]);
        }

        void Union(int x, int y) {
            int px = find(x), py = find(y);
            if (px != py) {
                if (size[px] < size[py]) swap(px, py);
                parent[py] = px;
                size[px] += size[py];
            }
        }

        int getSize(int x) {
            return size[find(x)];
        }
    };

    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int idx = 0;

        vector<vector<int>> id(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 1) id[i][j] = idx++;


        DSU dsu(idx);
        for (int i = 0; i < n; i++) {
            vector<int> servers;
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 1) servers.push_back(id[i][j]);
            for (int k = 1; k < servers.size(); k++)
                dsu.Union(servers[0], servers[k]);
        }
        for (int j = 0; j < m; j++) {
            vector<int> servers;
            for (int i = 0; i < n; i++)
                if (grid[i][j] == 1) servers.push_back(id[i][j]);
            for (int k = 1; k < servers.size(); k++)
                dsu.Union(servers[0], servers[k]);
        }

        vector<int> count(idx, 0);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 1) count[dsu.find(id[i][j])]++;

        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 1 && count[dsu.find(id[i][j])] > 1) ans++;
        return ans;
    }
};
