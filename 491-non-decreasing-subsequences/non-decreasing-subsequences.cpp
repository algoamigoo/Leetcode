class Solution {
public:
    void backtrack(set<vector<int>> &ans, int i, vector<int> &nums, vector<int> &curr) {
        if (curr.empty() || curr.back() <= nums[i]) {
            curr.push_back(nums[i]);
            if (curr.size() >= 2) ans.insert(curr);
            if (i + 1 < nums.size()) backtrack(ans, i + 1, nums, curr);
            curr.pop_back();
        }
        if (i + 1 < nums.size()) backtrack(ans, i + 1, nums, curr);
    }

    vector<vector<int>> findSubsequences(vector<int> &nums) {
        set<vector<int>> ans;
        vector<int> curr;
        for (int i = 0; i < nums.size() - 1; i++) {
            backtrack(ans, i, nums, curr);
        }
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};
