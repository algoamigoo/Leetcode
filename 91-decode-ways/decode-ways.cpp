class Solution {
public:
    vector<int> dp; // DP array to store memoized results
    
    int func(int i, string s, int n) {
        // Base case: reached the end of the string
        if (i >= n) {
            return 1;
        }
        
        // If already computed, return cached result
        if (dp[i] != -1) {
            return dp[i];
        }
        
        // If current character is '0', it can't form a valid decoding
        if (s[i] == '0') {
            return dp[i] = 0;
        }
        
        // Single-digit decoding
        int ways = func(i + 1, s, n);
        
        // Two-digit decoding if possible
        if (i + 1 < n) {
            int num = (s[i] - '0') * 10 + (s[i + 1] - '0');
            if (num >= 10 && num <= 26) {
                ways += func(i + 2, s, n);
            }
        }
        
        // Cache and return result
        return dp[i] = ways;
    }
    
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') {
            return 0;
        }
        int n = s.length();
        dp.assign(n, -1);
        return func(0, s, n);
    }
};