class Solution {
public:
    int n;
    vector<vector<int>> dp;

    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if (a[0] < b[0]) return true;
        if (a[0] == b[0]) return a[1] < b[1];
        return false;
    }

    int func(int i, vector<vector<int>>& events, int k) {
        if (k == 0 || i == n) return 0;
        if (dp[i][k] != -1) return dp[i][k];

        int st = events[i][0];
        int end = events[i][1];
        int val = events[i][2];

        int notTake = func(i + 1, events, k);

        int next = upper_bound(events.begin() + i, events.end(), end, 
                              [](int t, const vector<int>& v) { return t < v[0]; }) - events.begin();
        int take = val + func(next, events, k - 1);

        return dp[i][k] = max(take, notTake);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end(), cmp);
        n = events.size();
        dp.assign(n, vector<int>(k + 1, -1));
        return func(0, events, k);
    }
};