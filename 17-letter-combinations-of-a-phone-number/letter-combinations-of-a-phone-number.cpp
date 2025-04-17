class Solution {
public:
    vector<string> ans;
    int n;
    void solve(int k, string digits, string temp, vector<vector<char>> &mapping) {
        if (k == digits.length()) {
            if (!temp.empty())
                ans.push_back(temp);
            return;
        }

        for (int j = 0; j < mapping[digits[k] - '0'].size(); j++) {
            temp.push_back(mapping[digits[k] - '0'][j]);
            solve(k + 1, digits, temp, mapping);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<vector<char>> mapping(10);

        mapping[0] = {' '};
        mapping[1] = {};
        mapping[2] = {'a', 'b', 'c'};
        mapping[3] = {'d', 'e', 'f'};
        mapping[4] = {'g', 'h', 'i'};
        mapping[5] = {'j', 'k', 'l'};
        mapping[6] = {'m', 'n', 'o'};
        mapping[7] = {'p', 'q', 'r', 's'};
        mapping[8] = {'t', 'u', 'v'};
        mapping[9] = {'w', 'x', 'y', 'z'};
        
        string temp = "";
        solve(0, digits, temp, mapping);

        return ans;
    }
};