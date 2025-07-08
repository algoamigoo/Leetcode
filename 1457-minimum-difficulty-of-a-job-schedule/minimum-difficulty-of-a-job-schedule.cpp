class Solution {
public:
    int n;
    int dp[301][11][301]; // i, curr_d, j

    int func(int i, vector<int>& v, int d, int curr_d, int j) {
        if (i == n) {
            if (curr_d > d) return 0;
            return INT_MAX;
        }

        if (curr_d > d) return INT_MAX;

        if (dp[i][curr_d][j] != -1) return dp[i][curr_d][j];

        // Option 1: Don't take partition ending here
        int nottake = func(i + 1, v, d, curr_d, j);

        // Option 2: Take partition ending here
        int mx = 0;
        for (int ind = j; ind <= i; ind++) {
            mx = max(mx, v[ind]);
        }

        int take = func(i + 1, v, d, curr_d + 1, i + 1);
        if (take != INT_MAX) take += mx;

        return dp[i][curr_d][j] = min(nottake, take);
    }

    int minDifficulty(vector<int>& v, int d) {
        n = v.size();
        if (d > n) return -1;

        memset(dp, -1, sizeof(dp));
        int ans = func(0, v, d, 1, 0);
        return (ans == INT_MAX) ? -1 : ans;
    }
};
