class Solution {
public:
    int n;
    int func(int i, vector<pair<int,int>> &p, vector<int>& dp) {
        if (i >= n)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        // Don't take current number
        int nottake = func(i + 1, p, dp);
        
        // Take current number, skip next if it's adjacent
        int take = p[i].first * p[i].second;
        if (i + 1 < n && p[i + 1].first == p[i].first + 1)
            take += func(i + 2, p, dp); // Skip p[i+1] if it's p[i].first + 1
        else
            take += func(i + 1, p, dp);
        
        return dp[i] = max(take, nottake);
    }
    int deleteAndEarn(vector<int>& nums) {
        // 2 3 4
        map<int,int> freq;

        for (int i = 0; i < nums.size(); i++)
            freq[nums[i]]++;
        vector<pair<int,int>> p;
        for (auto it : freq) {
            p.push_back({it.first, it.second});
        }
        
        n = p.size();
        vector<int> dp(n + 1, -1); // Initialize dp after setting n
        
        sort(p.begin(), p.end());
        // que becomes to maximise sum by picking num's sum
        // such that if i picked nums[i] i cant pick nums[i]+1 and nums[i-1]
        return func(0, p, dp); 
    }
};