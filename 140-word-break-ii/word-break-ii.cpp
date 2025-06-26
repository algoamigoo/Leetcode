class Solution {
public:
    int n;
    
    void func(int i, string &s, vector<string>& wordDict, string t, vector<string>& ans) {
        if (i == n) {
            if (t.back() == ' ') t.pop_back(); // Remove trailing space
            ans.push_back(t);
            return;
        }

        for (int j = i + 1; j <= n; ++j) {
            string word = s.substr(i, j - i);
            if (find(wordDict.begin(), wordDict.end(), word) != wordDict.end()) {
                func(j, s, wordDict, t + word + " ", ans);
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        vector<string> ans;
        func(0, s, wordDict, "", ans);
        return ans;
    }
};
