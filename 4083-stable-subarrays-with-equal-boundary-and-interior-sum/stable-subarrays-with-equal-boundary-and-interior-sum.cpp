class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        map<pair<long long, int>, long long> m;
        int n = capacity.size();
        vector<long long> pre(n);
        pre[0] = capacity[0];
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + capacity[i];
        }
        long long c = 0;
        for (int r = 2; r < n; r++) {
            m[{pre[r - 2], capacity[r - 2]}]++;
            long long pLeft = pre[r] - 2 * capacity[r];
            c += m[{pLeft, capacity[r]}];
        }
        return c;
    }
};