class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& sf) {
        int n = s.size();
        vector<int> v(n + 1, 0);
        for (const auto& shift : sf) {
            int start = shift[0], end = shift[1], direction = shift[2];
            v[start] += (direction == 1) ? 1 : -1;
            v[end + 1] -= (direction == 1) ? 1 : -1;
        }
        int shift = 0;
        for (int i = 0; i < n; ++i) {
            shift += v[i];
            v[i] = shift; 
        }
        for(int i=0;i<n;i++){
            int netShift = (v[i] % 26 + 26) % 26;
            s[i] = 'a' + (s[i] - 'a' + netShift) % 26;
        }
        
        return s;
    }
};
