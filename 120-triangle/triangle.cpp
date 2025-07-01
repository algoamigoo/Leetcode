class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(), vector<int>(0));
        int INF = INT_MAX;
        for (int r = 0; r < triangle.size(); ++r) {
            dp[r].resize(triangle[r].size(), INF);
        }

        return dfs(0, 0, triangle, dp);
    }

private:
    int dfs(int row, int col, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        if (row >= triangle.size()) {
            return 0;
        }
        if (dp[row][col] != INT_MAX) {
            return dp[row][col];
        }

        dp[row][col] = triangle[row][col] + 
        min(dfs(row + 1, col, triangle, dp), dfs(row + 1, col + 1, triangle, dp));
        return dp[row][col];
    }
};