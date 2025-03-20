class Solution {
private:
    int solve(int i, int target, int currq, vector<vector<int>>& q, vector<vector<int>>& dp) {
        // Base cases
        if (target == 0) return currq;           
        if (currq >= q.size() || target < 0)
            return q.size() + 1;

        if (dp[target][currq] != -1) 
        return dp[target][currq];

        int res = solve(i, target, currq + 1, q, dp);

        if (q[currq][0] <= i && i <= q[currq][1])
            res = min(res, solve(i, target - q[currq][2], currq + 1, q, dp));

        return dp[target][currq] = res;
    }

public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int ans = -1;
        for (int i = 0; i < nums.size(); ++i) {
            vector<vector<int>> dp(nums[i] + 1, vector<int>(queries.size() + 1, -1));
            ans = max(ans, solve(i, nums[i], 0, queries, dp));
        }

        return (ans > queries.size()) ? -1 : ans;
    }
};