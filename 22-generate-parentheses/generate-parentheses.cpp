class Solution {
public:
    void backtrack(int o, int c, int n, string& s, vector<string>& ans) {
        if (s.size() == 2 * n) {
            ans.push_back(s);
            return;
        }
        if (o < n) {
            s.push_back('(');
            backtrack(o + 1, c, n, s, ans);
            s.pop_back();
        }
        if (c < o) {
            s.push_back(')');
            backtrack(o, c + 1, n, s, ans);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        backtrack(0, 0, n, s, ans);
        return ans;
    }
};