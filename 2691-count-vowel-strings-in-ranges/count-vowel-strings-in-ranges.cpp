class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        vector<int> w(words.size(), 0);
        for (int i = 0; i < words.size(); i++) {
            char first = words[i][0];
            char last = words[i][words[i].size() - 1];
            if (find(vowels.begin(), vowels.end(), first) != vowels.end() &&
                find(vowels.begin(), vowels.end(), last) != vowels.end()) {
                w[i] = 1;
            }
        }
        vector<int> pre(w.size() + 1, 0);
        for (int i = 0; i < w.size(); i++) {
            pre[i + 1] = pre[i] + w[i];
        }
        vector<int> ans;
        for (const auto& query : queries) {
            int li = query[0];
            int ri = query[1];
            ans.push_back(pre[ri + 1] - pre[li]);
        }

        return ans;
    }
};
