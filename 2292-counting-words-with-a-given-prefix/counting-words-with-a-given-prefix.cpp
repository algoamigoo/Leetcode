class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int c = 0;
        for (string& word : words) {
            //word.find(pref): Searches for pref in word.
            //If pref is found at the beginning (index 0), 
            //it means word starts with pref, so we count it.
            if (word.find(pref) == 0) {
                c++;
            }
        }
        return c;
    }
};