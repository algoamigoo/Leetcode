class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int totalSubsets = 1 << n;
        int ans = 0;
        
        for(int mask = 0; mask < totalSubsets; mask++) {
            int subsetXOR = 0;
            for(int i = 0; i < n; i++) {
                if(mask & (1 << i)) { // If bit is set, include nums[i]
                    subsetXOR ^= nums[i];
                }
            }
            ans += subsetXOR;
        }
        return ans;
    }
};