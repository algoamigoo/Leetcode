class Solution {
public:
    vector<vector<string>> ans;
    int len;

    bool ispali(string& curr) {
        for (int i = 0; i < curr.length() / 2; i++) {
            if (curr[i] != curr[curr.length() - i - 1])
                return false;
        }
        return true;
    }

    void backtrack(int i, string& s, vector<string>& curr) {
        if (i == len) {
            ans.push_back(curr);
            return;
        }

        for (int j = i; j < len; j++) {
            string temp = s.substr(i, j - i + 1);
            if (!ispali(temp))
            continue;

            curr.push_back(temp);
            backtrack(j + 1, s, curr);
            curr.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        len = s.length();
        vector<string> curr;
        backtrack(0, s, curr);
        return ans;
    }
};
