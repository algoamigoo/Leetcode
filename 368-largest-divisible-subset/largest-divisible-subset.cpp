class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};
        
        // Sort the array in ascending order
        sort(nums.begin(), nums.end());
        
        // dp[i] represents the length of the largest subset ending at index i
        vector<int> dp(n, 1);
        
        // prev[i] stores the previous index in the largest subset ending at i
        vector<int> prev(n, -1);
        
        // Keep track of max length and its ending index
        int maxLen = 1;
        int maxIndex = 0;
        
        // Fill dp array
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                maxIndex = i;
            }
        }
        
        // Reconstruct the answer
        vector<int> result;
        while (maxIndex != -1) {
            result.push_back(nums[maxIndex]);
            maxIndex = prev[maxIndex];
        }
        
        // Reverse to get ascending order
        reverse(result.begin(), result.end());
        return result;
    }
};