class Solution {
public:
    bool isvalid(int x, int y, int m, int n) {
        if (x >= 0 && y >= 0 && x < m && y < n)
            return true;
        return false;
    }
void dfs(int x, int y, vector<vector<bool>>& vis, vector<vector<int>>& v, int m, int n) {
        vis[x][y] = true;
        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};

        for (int i = 0; i < 4; i++) {
            int newx = x + dx[i];
            int newy = y + dy[i];

            if (isvalid(newx, newy, m, n) && !vis[newx][newy] && v[newx][newy] >= v[x][y]) {
                dfs(newx, newy, vis, v, m, n);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& v) {
        int m = v.size();
        int n = v[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

       for (int i = 0; i < m; i++) {
            dfs(i, 0, pacific, v, m, n);
            dfs(i, n - 1, atlantic, v, m, n);
        }
        for (int j = 0; j < n; j++) {
            dfs(0, j, pacific, v, m, n);
            dfs(m - 1, j, atlantic, v, m, n);
        }

        vector<vector<int>> ans;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};