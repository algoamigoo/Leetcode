class Solution {
public:
    int n, m;

    int func(int i, int j, vector<vector<bool>> &vis, vector<vector<int>>& grid) {
        vis[i][j] = true;
        int area = 1;
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        for (int k = 0; k < 4; k++) {
            int nx = i + dx[k];
            int ny = j + dy[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                !vis[nx][ny] && grid[nx][ny] == 1) {
                area += func(nx, ny, vis, grid);
            }
        }
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int mx = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    mx = max(mx, func(i, j, vis, grid));
                }
            }
        }

        return mx;
    }
};
