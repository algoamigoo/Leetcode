class Solution {
public:
    long long dp[100006][2];

    long long rec(int i, int parity, vector<int>& nums) {

        int n = nums.size();
        if (i >= n) return 0;

        if (dp[i][parity] != -1) 
        return dp[i][parity];
        
        long long curr = nums[i];
        if (parity == 0) 
        curr = -nums[i];

        long long take = curr + rec(i + 1, 1 - parity, nums);
        long long not_take = rec(i + 1, parity, nums);

        dp[i][parity] = max(take, not_take);
        return dp[i][parity];
    }

    long long maxAlternatingSum(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return rec(0, 1, nums);
        }
};
