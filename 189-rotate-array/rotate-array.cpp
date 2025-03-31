class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        if (n == 1 || k == 0) return;
        reverse(nums.begin(), nums.end());       // Reverse the entire array
        reverse(nums.begin(), nums.begin() + k); // Reverse first k elements
        reverse(nums.begin() + k, nums.end());   // Reverse the remaining elements
    }
};
