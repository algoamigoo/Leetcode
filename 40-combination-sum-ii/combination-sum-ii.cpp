class Solution {
public:
    vector<vector<int>> result;

    void backtrack(int i, vector<int>& candidates, vector<int>& temp, int sum, int target) {
        if (sum == target) {
            result.push_back(temp);
            return;
        }

        if (i >= candidates.size() || sum > target)
            return;

        temp.push_back(candidates[i]);
        backtrack(i + 1, candidates, temp, sum + candidates[i], target);
        temp.pop_back();

        int next = i + 1;
        while (next < candidates.size() && candidates[next] == candidates[i])
        next++;

        // Exclude current element and move to next distinct one
        backtrack(next, candidates, temp, sum, target);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        result.clear();
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        backtrack(0, candidates, temp, 0, target);
        return result;
    }
};
