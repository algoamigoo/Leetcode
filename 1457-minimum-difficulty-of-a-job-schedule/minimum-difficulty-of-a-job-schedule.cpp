class Solution {
public:
    int n;
    int dp[301][11];
    int func(int i, int d, vector<int>& v) {
        if (d == 0 && i == n) return 0;
        if (d == 0 || i == n) return INT_MAX;
        if (dp[i][d] != -1) return dp[i][d];

        int mx = 0;
        int res = INT_MAX;

        for (int j = i; j < n; ++j) {
            mx = max(mx, v[j]);
            int next = func(j + 1, d - 1, v);
            if (next != INT_MAX)
                res = min(res, mx + next);
        }

        return dp[i][d] = res;
    }

    int minDifficulty(vector<int>& v, int d) {
        n = v.size();
        if (d > n) return -1;

        memset(dp, -1, sizeof(dp));
        int ans = func(0, d, v);
        return ans == INT_MAX ? -1 : ans;
    }
};
