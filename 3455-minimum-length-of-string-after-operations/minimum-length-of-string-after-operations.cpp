class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        unordered_map<char, int> freq;
        for (char c : s)
        freq[c]++;

        int result = 0;
        for (auto it : freq) {
            if (it.second%2)
            result++; 
            else 
            result+=2;
        }

        return result;
    }
};
