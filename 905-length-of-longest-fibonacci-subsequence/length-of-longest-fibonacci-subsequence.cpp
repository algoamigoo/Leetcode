class Solution {
public:
    int func(int i, int j, vector<int>& arr, vector<vector<int>>& dp, unordered_map<int, int>& m) {
        if (dp[i][j] != 0) return dp[i][j];
        int n = arr.size();
        int next_val = arr[i] + arr[j];
        if (m.find(next_val) != m.end()) {
            int k = m[next_val];
            dp[i][j] = 1 + func(j, k, arr, dp, m); 
        }

        return dp[i][j];
    }

    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        unordered_map<int, int> m;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            m[arr[i]] = i;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                dp[i][j] = func(i, j, arr, dp, m);
                ans = max(ans, dp[i][j]);
            }
        }
        if(ans>0)
        ans+=2;
        
        return ans; 
        }
};
