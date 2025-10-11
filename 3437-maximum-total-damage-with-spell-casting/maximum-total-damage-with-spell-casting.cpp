class Solution {
public:
    long long dp[100001];
    unordered_map<int, int> freq;

    long long func(int i, vector<pair<int,int>>& p) {
        int n = p.size();
        if (i == n) return 0;
        if (dp[i] != -1) return dp[i];

        // Option 1: Skip current
        long long notTake = func(i + 1, p);

        // Option 2: Take current and skip next within range ≤4
        long long take = 1LL * p[i].first * p[i].second;
        int j = i + 1;
        while (j < n && p[j].first - p[i].first <= 2) j++;
        take += func(j, p);

        return dp[i] = max(take, notTake);
    }

    long long maximumTotalDamage(vector<int>& power) {
        sort(power.begin(), power.end());

        for (int val : power) freq[val]++;

        vector<pair<int,int>> p;
        for (auto& it : freq) p.push_back({it.first, it.second});

        sort(p.begin(), p.end());
        memset(dp, -1, sizeof(dp));

        return func(0, p);
    }
};
