class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char, int> m2;
        vector<string> ans;
        for (int i = 0; i < words2.size(); i++) {
            unordered_map<char, int> temp;
            for (int j = 0; j < words2[i].length(); j++) {
                temp[words2[i][j]]++;
            }
            for (auto &[ch, freq] : temp) {
                m2[ch] = max(m2[ch], freq);
            }
        }
        for (int i = 0; i < words1.size(); i++) {
            unordered_map<char, int> m;
            for (int j = 0; j < words1[i].length(); j++) {
                m[words1[i][j]]++;
            }
            int f = 1;
            for (auto &[ch, freq] : m2) {
                if (m[ch] < freq) {
                    f = 0;
                    break;
                }
            }
            if (f) ans.push_back(words1[i]);
        }
        return ans;
    }
};
