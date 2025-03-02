int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

class Solution {
public:
    bool isValid(int x, int y, int n, int m) { 
        return x >= 0 && x < n && y >= 0 && y < m; }

    int dfs(int x, int y, vector<vector<int>>& matrix, vector<vector<int>>& dp, int n, int m) {
        if (dp[x][y]) return dp[x][y];

        int len = 1;
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (isValid(nx, ny, n, m) && matrix[nx][ny] > matrix[x][y])
                len = max(len, 1 + dfs(nx, ny, matrix, dp, n, m));
        }
        
        return dp[x][y] = len;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        int maxLen = 0;
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++) 
                maxLen = max(maxLen, dfs(i, j, matrix, dp, n, m));
        
        return maxLen;
    }
};
