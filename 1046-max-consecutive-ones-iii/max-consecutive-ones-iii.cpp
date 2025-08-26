class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        vector<int> zero_idx;
        zero_idx.push_back(0);
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) 
                zero_idx.push_back(i + 1);
        }
        zero_idx.push_back(nums.size() + 1);

        if (k >= zero_idx.size() - 2) return nums.size();

        int ans = 0;
        for (int i = 0; i + k + 1 < zero_idx.size(); i++) {
            ans = max(ans, zero_idx[i + k + 1] - zero_idx[i] - 1);
        }
        return ans;
    }
};
