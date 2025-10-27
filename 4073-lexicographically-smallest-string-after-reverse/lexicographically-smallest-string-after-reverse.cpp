class Solution {
public:
    string lexSmallest(string s) {
        string ans = s;
        int n = s.length();
        for(int k = 1; k <= n; k++) {
            string curr = s;
            reverse(curr.begin(), curr.begin() + k);
            ans = min(ans, curr);
            
            curr = s;
            reverse(curr.end() - k, curr.end());
            ans = min(ans, curr);
        }
        return ans;
    }
};