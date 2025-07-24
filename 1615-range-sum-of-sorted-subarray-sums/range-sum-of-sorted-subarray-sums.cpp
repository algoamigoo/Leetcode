class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> subarrays;
        const int MOD = 1e9 + 7;
        
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                subarrays.push_back(sum);
            }
        }
        sort(subarrays.begin(), subarrays.end());
        
        int result = 0;
        for (int i = left - 1; i < right; i++) {
            result = (result + subarrays[i]) % MOD;
        }
        
        return result;
    }
};