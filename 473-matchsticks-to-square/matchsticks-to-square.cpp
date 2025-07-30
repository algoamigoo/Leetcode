class Solution {
public:
    bool backtrack(vector<int>& matchsticks, vector<bool>& used, int startIndex, int currSum, int target, int sidesLeft) {
        if (sidesLeft == 0) return true;

        if (currSum == target) {
            // One side complete, start next side from index 0
            return backtrack(matchsticks, used, 0, 0, target, sidesLeft - 1);
        }

        for (int i = startIndex; i < matchsticks.size(); ++i) {
            if (used[i] || currSum + matchsticks[i] > target)
                continue;

            used[i] = true;
            if (backtrack(matchsticks, used, i + 1, currSum + matchsticks[i], target, sidesLeft))
                return true;
            used[i] = false;
            if (currSum == 0) break;
        }

        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        int total = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (total % 4 != 0 || matchsticks.size() < 4) return false;

        int target = total / 4;
        vector<bool> used(matchsticks.size(), false);

        sort(matchsticks.rbegin(), matchsticks.rend());
        return backtrack(matchsticks, used, 0, 0, target, 4);
    }
};
