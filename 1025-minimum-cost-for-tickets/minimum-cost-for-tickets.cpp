class Solution {
public:
    int n;
    vector<int> dp;
    int func(int i, vector<int>& days, vector<int>& costs) {
        if (i >= n)
        return 0;

        int today = days[i];

        if (dp[i] != -1)
        return dp[i];

        // 1-day pass
        int next1 = i + 1;
        int c1 = costs[0] + func(next1, days, costs);

        // 7-day pass
        int next7 = i;
        while (next7 < n && days[next7] <= today + 6) {
            next7++;
        }
        int c2 = costs[1] + func(next7, days, costs);

        // 30-day pass
        int next30 = i;
        while (next30 < n && days[next30] <= today + 29) {
            next30++;
        }
        int c3 = costs[2] + func(next30, days, costs);

        return dp[i] = min({c1, c2, c3});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        n = days.size();
        dp.resize(n + 1, -1);
        return func(0, days, costs);
    }
};