class Solution {
typedef long long ll;
const int mod = 1e9 + 7;
public:
    int solve(int i, int g, vector<vector<int>>& mat, vector<vector<int>>& dp) {
        if(i == mat.size()) return g == 1;
        if(dp[i][g] != -1) return dp[i][g];
        ll ans = 0;
        for(int j = 0; j < mat[i].size(); j++) {
            int ng = mat[i][j];
            if(g != 0) ng = gcd(g, ng);
            ans = (ans + solve(i + 1, ng, mat, dp)%mod)%mod;
        }
        return dp[i][g] = (int)ans;
    }
    int countCoprime(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> dp(n, vector<int>(150 + 1, -1));
        return solve(0, 0, mat, dp);
    }
};