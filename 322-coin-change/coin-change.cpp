class Solution {
public:
    int n;

    int func(int i, vector<int>& coins, int amount, vector<vector<int>>& dp) {
        // Base cases
        if (amount == 0)
            return 0;
        if (amount < 0 || i == n)
            return INT_MAX;
        if (dp[i][amount] != -1)
            return dp[i][amount];

        // Option 1: Skip the current coin
        int skip = func(i + 1, coins, amount, dp);

        // Option 2: Take the current coin (and stay at the same index)
        int take = INT_MAX;
        if (amount >= coins[i]) {
            int next = func(i, coins, amount - coins[i], dp);
            if (next != INT_MAX)
                take = 1 + next;
        }
        return dp[i][amount] = min(skip, take);
    }

    int coinChange(vector<int>& coins, int amount) {
        n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = func(0, coins, amount, dp);
        return (ans == INT_MAX ? -1 : ans);
    }
};