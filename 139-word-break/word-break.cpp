class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end()); 
        vector<bool> dp(s.length() + 1, false);
        dp.back() = true; 

        for (int i = s.length() - 1; i >= 0; i--) {
            for (int j = i; j < s.length(); j++) {
                if (dp[j + 1] && st.find(s.substr(i, j - i + 1)) != st.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
};
