class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int, int>> v;
        
        for (int i = 0; i < n; i++) {
            v.push_back({nums2[i], nums1[i]});
        }
        sort(v.rbegin(), v.rend());
        priority_queue<int, vector<int>, greater<int>> pq;

        long long sum = 0, ans = 0;
        
        for (int i = 0; i < k; i++) {
            pq.push(v[i].second);
            sum += v[i].second;
        }
        ans = sum * v[k - 1].first;

        for (int i = k; i < n; i++) {
            pq.push(v[i].second);
            sum += v[i].second;
            sum -= pq.top();
            pq.pop();
            ans = max(ans, sum * v[i].first);
        }

        return ans;
    }
};
