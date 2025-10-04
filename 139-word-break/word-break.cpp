class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[n] = true; // empty suffix is valid

        int maxLen = 0;
        for (auto &w : wordDict) maxLen = max(maxLen, (int)w.size()); // optimization: no need to check longer words

        for (int i = n - 1; i >= 0; i--) {
            for (int len = 1; len <= maxLen && i + len <= n; len++) {
                if (dp[i + len] && st.find(s.substr(i, len)) != st.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
};
