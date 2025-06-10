class Solution {
public:
    int rec(int i, vector<int>& nums, int n, vector<int>& dp) {
        if (i >= n - 1) return 0;
        if (dp[i] != -1) return dp[i];

        int ans = 1e9;
        for (int j = 1; j <= nums[i]; j++) {
            if (i + j < n) {
                ans = min(ans, 1 + rec(i + j, nums, n, dp));
            }
        }
        return dp[i] = ans;
    }

    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return rec(0, nums, n, dp);
    }
};
