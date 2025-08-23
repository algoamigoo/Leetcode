class Solution {
public:
    int n, m;
    int ans = 0;
    vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0) {
            return 0;
        }

        int gold = grid[i][j];
        grid[i][j] = 0; // mark visited

        int best = 0;
        for (int d = 0; d < 4; d++) {
            int ni = i + dirs[d][0];
            int nj = j + dirs[d][1];
            best = max(best, dfs(grid, ni, nj));
        }

        grid[i][j] = gold; // backtrack
        return gold + best;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] > 0) {
                    ans = max(ans, dfs(grid, i, j));
                }
            }
        }
        return ans;
    }
};
