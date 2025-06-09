class Solution {
public:
    int n;
    string s;
    unordered_map<string, bool> memo;

    bool solve(int i, int open) {
        if (open < 0) return false;
        if (i == n) return open == 0;

        string key = to_string(i) + "," + to_string(open);
        if (memo.count(key)) return memo[key];

        if (s[i] == '(')
            return memo[key] = solve(i+1, open+1);
        else if (s[i] == ')')
            return memo[key] = solve(i+1, open-1);
        else {
            return memo[key] =
                solve(i+1, open) ||         // treat '*' as empty
                solve(i+1, open+1) ||       // treat '*' as '('
                solve(i+1, open-1);         // treat '*' as ')'
        }
    }

    bool checkValidString(string str) {
        s = str;
        n = s.length();
        return solve(0, 0);
    }
};
