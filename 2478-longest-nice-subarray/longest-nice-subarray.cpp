class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int curr = 0;      // Current bitwise OR of window
        int mx = 0;
        int left = 0;      // Left pointer of sliding window
        
        for(int right = 0; right < nums.size(); right++) {
            while ((nums[right] & curr) != 0) {
                curr &= ~nums[left];  // Remove leftmost number
                left++;
            }
            curr |= nums[right];
            mx = max(mx, right - left + 1);
        }
        return mx;
    }
};