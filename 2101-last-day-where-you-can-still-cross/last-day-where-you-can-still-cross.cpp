class Solution {
public:
    int rows, cols;
    vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

    bool dfs(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& vis) {
        if (r == rows - 1) return true; // reached bottom row
        vis[r][c] = true;

        for (auto& d : dirs) {
            int nr = r + d[0], nc = c + d[1];
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols &&
                !vis[nr][nc] && grid[nr][nc] == 0) {
                if (dfs(nr, nc, grid, vis)) return true;
            }
        }
        return false;
    }

    bool func(int day, vector<vector<int>>& cells) {
        vector<vector<int>> grid(rows, vector<int>(cols, 0));
        // Mark water for first `day` days
        for (int i = 0; i <= day; i++) {
            grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
        }
        vector<vector<bool>> vis(rows, vector<bool>(cols, false));

        // Try starting from any land cell in top row
        for (int c = 0; c < cols; c++) {
            if (grid[0][c] == 0 && !vis[0][c]) {
                if (dfs(0, c, grid, vis)) return true;
            }
        }
        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        rows = row;
        cols = col;

        int l = 0, r = row * col - 1;
        int ans = 0;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (func(mid, cells)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return ans + 1; // +1 because days are 1-indexed in problem
    }
};
