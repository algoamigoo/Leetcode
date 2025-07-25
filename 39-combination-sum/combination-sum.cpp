class Solution {
public:
    vector<vector<int>> result;

    void backtrack(int i, vector<int>& candidates, vector<int>& temp, int sum, int target) {
        if (sum == target) {
            result.push_back(temp);
            return;
        }
        if (i == candidates.size() || sum > target)
            return;

        // Include current element
        temp.push_back(candidates[i]);
        backtrack(i, candidates, temp, sum + candidates[i], target);
        temp.pop_back();  // backtrack

        // Exclude current element and move to next
        backtrack(i + 1, candidates, temp, sum, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        result.clear();
        backtrack(0, candidates, temp, 0, target);
        return result;
    }
};
