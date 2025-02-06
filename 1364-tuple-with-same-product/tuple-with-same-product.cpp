class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> m;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                m[nums[i] * nums[j]]++;
            }
        }

        long long ans = 0;
        for (auto& [key, freq] : m) {
            ans += (long long)freq * (freq - 1) / 2;
        }

        return ans * 8;
    }
};
