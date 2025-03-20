class Solution {
private:
    int solve(vector<vector<int>>& q, int i, int t, int k, vector<vector<int>>& dp) {
        // Base cases
        if (t == 0) return k;
        if (k >= q.size() || t < 0)      
            return q.size() + 1;
        
        // Memoized result
        if (dp[t][k] != -1) return dp[t][k];
        
        // Skip current query
        int res = solve(q, i, t, k + 1, dp);
        
        // Use query if index in range
        if (q[k][0] <= i && i <= q[k][1])
            res = min(res, solve(q, i, t - q[k][2], k + 1, dp));
        
        return dp[t][k] = res;
    }

public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int ans = -1;
        
        for (int i = 0; i < nums.size(); ++i) {
            vector<vector<int>> dp(nums[i] + 1,vector<int>(queries.size() + 1, -1));
            ans = max(ans, solve(queries, i, nums[i], 0, dp));
        }
        
        return (ans > queries.size()) ? -1 : ans;
    }
};