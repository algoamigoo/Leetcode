typedef __int128 ll;

class Solution {
public:
    int n;

    bool func(int i, ll temp, vector<int>& nums, ll target, ll total) {
        if (temp == target && total / temp == target)
            return true;
        if (i == n || temp > target)
            return false;
        if (func(i + 1, temp * nums[i], nums, target, total))
            return true;
        if (func(i + 1, temp, nums, target, total))
            return true;
        return false;
    }

    bool checkEqualPartitions(vector<int>& nums, long long target) {
        n = nums.size();
        ll total = 1;
        for (int i = 0; i < n; i++)
            total *= nums[i];
        if (total != (ll)target * target)
            return false;
        return func(0, 1, nums, target, total);
    }
};
