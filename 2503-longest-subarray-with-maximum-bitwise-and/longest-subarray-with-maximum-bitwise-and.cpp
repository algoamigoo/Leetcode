class Solution {
public:
    int longestSubarray(vector<int>& nums) { int mx = *max_element(nums.begin(), nums.end());
        int ans = 0, c = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == mx) {
                c++;
                ans = max(ans, c);
            } else {
                c = 0;
            }
        }

        return ans;
    }
};