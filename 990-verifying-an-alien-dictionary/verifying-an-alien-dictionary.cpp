class Solution {
public:
    unordered_map<char, int> m;

    static bool cmp(const string& s1, const string& s2, unordered_map<char, int>& m) {
        int l1 = s1.length();
        int l2 = s2.length();
        int i = 0, j = 0;
        while (i < l1 && j < l2) {
            if (m[s1[i]] > m[s2[j]]) return false;
            if (m[s1[i]] < m[s2[j]]) return true;
            i++;
            j++;
        }
        return l1 <= l2;
    }

    bool isAlienSorted(vector<string>& words, string order) {
        for (int i = 0; i < order.length(); i++) {
            m[order[i]] = i + 1;
        }

        vector<string> v = words;

        sort(words.begin(), words.end(), [&](const string& a, const string& b) {
            return cmp(a, b, m);
        });

        for (int i = 0; i < v.size(); i++) {
            if (words[i] != v[i]) 
            return false;
        }
        return true;
    }
};
