class Solution {
public:
    int n, m;
    void rec(int i, int j, vector<vector<int>>& ans, vector<vector<int>>& grid, int k) {
        vector<int> temp;
        for (int x = i; x < i + k; x++) {
            for (int y = j; y < j + k; y++) {
                temp.push_back(grid[x][y]);
            }
        }
        sort(temp.begin(), temp.end());
        int mn = INT_MAX;
        if (temp.size() > 1) {
            for (int z = 0; z < temp.size() - 1; z++) {
                if (temp[z] != temp[z + 1]) {
                    mn = min(mn, abs(temp[z] - temp[z + 1]));
                }
            }
        } else {
            mn = 0;
        }
        ans[i][j] = mn == INT_MAX ? 0 : mn;
    }

    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> ans(n - k + 1, vector<int>(m - k + 1));
        for (int i = 0; i <= n - k; i++) {
            for (int j = 0; j <= m - k; j++) {
                rec(i, j, ans, grid, k);
            }
        }
        return ans;
    }
};