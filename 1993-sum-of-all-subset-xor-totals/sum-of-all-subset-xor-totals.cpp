class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return func(nums, 0, 0);
    }
    
    int func(vector<int>& nums, int i, int currXor) {
        if (i == nums.size()) return currXor;
        return func(nums, i+1, currXor ^ nums[i]) + func(nums, i+1, currXor);
    }
};
