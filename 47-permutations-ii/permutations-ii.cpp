class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(vector<int>& nums, vector<int>& curr, vector<bool>& used) {
        if (curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
             if (used[i] || (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]))
            continue;
            
            used[i] = true;
            curr.push_back(nums[i]);
            backtrack(nums, curr, used);
            curr.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<int> curr;
        vector<bool> used(n, false);
        sort(nums.begin(),nums.end());
        backtrack(nums, curr, used);
        return ans;
    }
};
