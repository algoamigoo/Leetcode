class Solution {
public:
    bool isvalid(int i, int j, int n, int m) {
        if (i < n && j < m && i >= 0 && j >= 0)
            return true;
        return false;
    }

    void dfs(int i, int j, vector<vector<bool>> &vis, vector<vector<char>>& grid, int c) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> cx = {0, 0, 1, -1};
        vector<int> cy = {1, -1, 0, 0};

        if (!vis[i][j] && grid[i][j] == '1') {
            vis[i][j] = true;
            for (int x = 0; x < 4; x++) {
                int ni = i + cx[x];
                int nj = j + cy[x];
                if (isvalid(ni, nj, n, m)) {
                    dfs(ni, nj, vis, grid, c + 1);
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int c = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    dfs(i, j, vis, grid, c);
                    c++;
                }
            }
        }
        return c;
    }
};