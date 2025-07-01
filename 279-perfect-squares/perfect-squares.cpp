class Solution {
public:
    vector<vector<int>> dp; // Dynamic DP array based on input size
    
    int func(int i, int n, vector<int>& v) {
        if (n == 0)
            return 0;
        if (i >= v.size() || n < 0)
            return INT_MAX;
        
        if (dp[i][n] != -1)
            return dp[i][n];
        
        int take = INT_MAX;
        if (v[i] <= n && func(i, n - v[i], v) != INT_MAX)
            take = 1 + func(i, n - v[i], v);
        
        int nottake = func(i + 1, n, v);
        return dp[i][n] = min(take, nottake);
    }
    
    int numSquares(int n) {
        // Generate perfect squares up to ⌊√n⌋
        vector<int> v;
        for (int i = 1; i * i <= n; ++i) {
            v.push_back(i * i);
        }
        
        // Initialize DP array with size [√n + 1][n + 1]
        dp.assign(v.size() + 1, vector<int>(n + 1, -1));
        
        return func(0, n, v);
    }
};