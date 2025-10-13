class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();

        vector<unordered_map<char, int>> m(n);
        for (int i = 0; i < words.size(); i++) {
            for (auto it : words[i]) m[i][it]++;
        }

        vector<string> ans;
        ans.push_back(words[0]);
        for (int i = 1; i < n; i++) {
            if (m[i] != m[i - 1]) ans.push_back(words[i]);
        }
        return ans;
    }
};