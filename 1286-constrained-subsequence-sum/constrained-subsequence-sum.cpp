class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        priority_queue<pair<int, int>> pq;
        pq.push({dp[0], 0});
        
        int ans = dp[0];
        
        for(int i = 1; i < n; i++) {
            while(!pq.empty() && pq.top().second < i - k) {
                pq.pop();
            }
            dp[i] = nums[i];
            if(!pq.empty()) {
                dp[i] = max(dp[i], nums[i] + pq.top().first);
            }
            pq.push({dp[i], i});
            
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
};