class Solution {
public:
    vector<vector<vector<int>>> dp;
    
    bool rec(int i, int j, int k, string& s1, string& s2, string& s3) {
        int n = s1.length();
        int m = s2.length();
        
        // Base cases
        if (i == n && j == m && k == s3.length()) return true;
        if (k >= s3.length() || i > n || j > m) return false;
        
        // Check memoization
        if (dp[i][j][k] != -1) 
        return dp[i][j][k];
        
        bool result = false;
        
        // Try taking from s1
        if (i < n && s1[i] == s3[k]) {
            result |= rec(i + 1, j, k + 1, s1, s2, s3);
        }
        
        // Try taking from s2
        if (j < m && s2[j] == s3[k]) {
            result |= rec(i, j + 1, k + 1, s1, s2, s3);
        }
        
        // Store result in dp
        dp[i][j][k] = result;
        return result;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length();
        int m = s2.length();
        
        // Check if lengths match
        if (n + m != s3.length()) 
        return false;
        
        // Initialize dp array with -1
        dp.assign(n + 1, vector<vector<int>>(m + 1, vector<int>(s3.length() + 1, -1)));
        
        return rec(0, 0, 0, s1, s2, s3);
    }
};