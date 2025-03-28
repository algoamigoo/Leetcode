class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        int count = 0;
        for (string w : words) {
            int i = 0, j = 0;
            bool valid = true;
            while (i < s.length() && j < w.length() && valid) {
                if (s[i] != w[j]) { valid = false; break; }
                int sCount = 1; while (i + 1 < s.length() && s[i] == s[i + 1]) { sCount++; i++; }
                int wCount = 1; while (j + 1 < w.length() && w[j] == w[j + 1]) { wCount++; j++; }
                if (sCount < 3 && sCount != wCount || sCount >= 3 && wCount > sCount) valid = false;
                i++; j++;
            }
            if (valid && i == s.length() && j == w.length()) count++;
        }
        return count;
    }
};