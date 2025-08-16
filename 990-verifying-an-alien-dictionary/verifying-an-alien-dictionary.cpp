class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        // Step 1: build mapping
        vector<char> mp(26);
        for (int i = 0; i < 26; i++) {
            mp[order[i] - 'a'] = 'a' + i; // map alien char to normal alphabet
        }

        // Step 2: translate each word
        vector<string> translated;
        for (auto &w : words) {
            string t;
            for (char c : w) t.push_back(mp[c - 'a']);
            translated.push_back(t);
        }

        // Step 3: check sorted
        return is_sorted(translated.begin(), translated.end());
    }
};
