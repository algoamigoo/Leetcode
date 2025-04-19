class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long count = 0;
        int n = nums.size();

        // Sort the array to enable binary search
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 1; ++i) {
            int curr = nums[i];
            // We look for nums[j] such that: lower - curr <= nums[j] <= upper - curr
            auto low = lower_bound(nums.begin() + i + 1, nums.end(), lower - curr);
            auto high = upper_bound(nums.begin() + i + 1, nums.end(), upper - curr);
            count += high - low;
        }

        return count;
    }
};
