class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> m;
        for (auto it : nums)
            m[it]++;

        int ans = 0;
        for (auto it = m.begin(); it != m.end(); ++it) {
            auto nxt = next(it);
            if (nxt != m.end() && nxt->first - it->first == 1) {
                ans = max(ans, it->second + nxt->second);
            }
        }
        return ans;
    }
};
