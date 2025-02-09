class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, int> m;
        long long n = nums.size(), goodPairs = 0;
        
        for(int i = 0; i < n; i++) {
            int diff = nums[i] - i;
            goodPairs += m[diff];
            m[diff]++;
        }
        
        return n * (n - 1) / 2 - goodPairs;
    }
};
