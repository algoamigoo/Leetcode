class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& vis, int& fishSum) {
        int n = grid.size(), m = grid[0].size();
        fishSum += grid[r][c];
        vis[r][c] = true;
        vector<int> dir = {-1, 0, 1, 0, -1};
        for (int d = 0; d < 4; ++d) {
            int nr = r + dir[d];
            int nc = c + dir[d + 1];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] > 0) {
                dfs(nr, nc, grid, vis, fishSum);
            }
        }
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int maxFish = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] > 0 && !vis[i][j]) {
                    int fishSum = 0;
                    dfs(i, j, grid, vis, fishSum);
                    maxFish = max(maxFish, fishSum); 
                }
            }
        }

        return maxFish;
    }
};
