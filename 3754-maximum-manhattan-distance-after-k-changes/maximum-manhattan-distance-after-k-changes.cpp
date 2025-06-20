class Solution {
public:
    int maxDistance(string s, int k) {
        int n = s.size();
        int x = 0, y = 0;
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            if (s[i] == 'N') {
                y++;
            } else if (s[i] == 'S') {
                y--;
            } else if (s[i] == 'E') {
                x++;
            } else if (s[i] == 'W') {
                x--;
            }
            
            int L = i + 1;
            int orig = abs(x) + abs(y);   
            int candidate = min(L, orig + 2 * k);  
            ans = max(ans, candidate);   
        }
        
        return ans;
    }
};