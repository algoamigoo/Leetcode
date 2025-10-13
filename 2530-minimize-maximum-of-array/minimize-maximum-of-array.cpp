class Solution {
public:
    bool func(int mid, vector<int>& nums, int n) {
        long long carry = 0;
        for (int i = n - 1; i > 0; i--) {
            if (nums[i] > mid) {
                carry += nums[i] - mid;
            } else {
                long long give = min(carry, (long long)(mid - nums[i]));
                carry -= give;
            }
        }
        return (nums[0] + carry) <= mid;
    }

    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();
        int mx = 0;
        for (int i = 0; i < n; i++) mx = max(mx, nums[i]);
        int l = 0, r = mx, ans = mx;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (func(mid, nums, n)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
