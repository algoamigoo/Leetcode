class Solution {
public:
    string s;
    int n;
    int dp[105][105]; // -1 = not visited, 0 = false, 1 = true

    bool func(int i, int open) {
        if (open < 0) return false; // too many closing brackets
        if (i == n) return open == 0;
        if (dp[i][open] != -1) return dp[i][open];

        bool ans = false;
        if (s[i] == '(') {
            ans = func(i + 1, open + 1);
        } else if (s[i] == ')') {
            ans = func(i + 1, open - 1);
        } else { // s[i] == '*'
            ans = func(i + 1, open)         // '*' as empty
                || func(i + 1, open + 1)    // '*' as '('
                || func(i + 1, open - 1);   // '*' as ')'
        }

        return dp[i][open] = ans;
    }

    bool checkValidString(string str) {
        s = str;
        n = s.length();
        memset(dp, -1, sizeof(dp));
        return func(0, 0);
    }
};
