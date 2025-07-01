class Solution {
public:
    int n;
    bool func(int i, vector<int>& nums, int target, vector<vector<int>>& dp) {
        if (target == 0) return true;
        if (i == n) return false;
        if (dp[i][target] != -1) return dp[i][target];
        
        bool take = false;
        if (target >= nums[i]) {
            take = func(i + 1, nums, target - nums[i], dp);
        }
        bool notTake = func(i + 1, nums, target, dp);
        
        return dp[i][target] = take || notTake;
    }
    
    bool canPartition(vector<int>& nums) {
        n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) 
        sum += nums[i];
        
        if (sum % 2) return false;
        
        int target = sum / 2;
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return func(0, nums, target, dp);
    }
};