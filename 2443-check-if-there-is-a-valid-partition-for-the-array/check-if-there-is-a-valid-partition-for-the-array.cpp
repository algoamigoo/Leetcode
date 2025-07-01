class Solution {
public:
    int n;
    bool func(int i, vector<int>& nums,vector<int> &dp) {
        
        if(i>=n)
        return true;
        if(dp[i]!=-1)
        return dp[i];
        
        // take 2
        if(i+1<n && nums[i]==nums[i+1]){
        if (func(i + 2, nums, dp)) {
                dp[i] = 1;
                return true;
            }
        }

        if(i+2<n){
            if(nums[i]==nums[i+1] && nums[i+1]==nums[i+2] 
            || nums[i+1]==nums[i]+1 && nums[i+2]==nums[i]+2){
            if (func(i + 3, nums, dp)) {
                    dp[i] = 1;
                    return true;
                }
            }
        }
        dp[i]=0;
        return false;
    }

    bool validPartition(vector<int>& nums) {
        n = nums.size();
        vector<int> dp(n+1,-1);
        return func(0, nums,dp);
    }
};