class Solution {
public:
    int mod = 1e9 + 7;

    int maxPerformance(int n, vector<int>& nums1, vector<int>& nums2, int k) {
        long long ans = 0;
        vector<pair<int,int>> p;
        for(int i = 0; i < nums1.size(); i++) {
            p.push_back({nums2[i], nums1[i]});
        }
        sort(p.begin(), p.end(), greater<>()); 

        priority_queue<int, vector<int>, greater<int>> q;
        long long sum = 0;
        for(int i = 0; i < min(k, n); i++) {
            sum += p[i].second;
            q.push(p[i].second);
            ans = max(ans, sum * (long long)p[i].first);
        }

        for(int i = k; i < n; i++) {
            int x = q.top();
            sum -= x;
            q.pop();
            q.push(p[i].second);
            sum += p[i].second;
            ans = max(ans, sum * (long long)p[i].first);
        }
        return ans % mod;
    }
};