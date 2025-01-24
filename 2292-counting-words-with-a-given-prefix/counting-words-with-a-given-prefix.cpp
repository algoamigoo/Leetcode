class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int c = 0;
        for (string& word : words) {
            if (word.find(pref) == 0) {
                c++;
            }
        }
        return c;
    }
};