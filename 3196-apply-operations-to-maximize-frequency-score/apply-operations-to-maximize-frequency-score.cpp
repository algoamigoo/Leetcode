class Solution {
public:
    typedef long long ll;

    bool func(int len, const vector<int>& a, const vector<ll>& pre, ll k, int n) {
        if (len == 0) return false;
        int i = 0;
        int j = len - 1;
        while (j < n) {
            int m = (i + j) / 2;
            ll x = a[m];
            ll left = 0, right = 0;
            if (m > i) {
                ll sumLeft = pre[m - 1];
                if (i > 0) sumLeft -= pre[i - 1];
                left = (ll)(m - i) * x - sumLeft;
            }
            if (m < j) {
                ll sumRight = pre[j] - pre[m];
                right = sumRight - (ll)(j - m) * x;
            }
            if (left + right <= k) return true;
            i++;
            j++;
        }
        return false;
    }

    int maxFrequencyScore(vector<int>& a, long long k) {
        int n = a.size();
        sort(a.begin(), a.end());
        vector<ll> pre(n);
        pre[0] = a[0];
        for (int i = 1; i < n; i++) pre[i] = pre[i - 1] + a[i];
        int l = 1, r = n, ans = 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (func(mid, a, pre, k, n)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};
