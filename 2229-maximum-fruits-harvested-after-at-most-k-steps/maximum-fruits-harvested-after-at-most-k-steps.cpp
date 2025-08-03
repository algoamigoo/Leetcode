class Solution {
public:
    vector<int> p, pre;

    int get(int l, int r) {
        int i = lower_bound(p.begin(), p.end(), l) - p.begin();
        int j = upper_bound(p.begin(), p.end(), r) - p.begin();
        return pre[j] - pre[i];
    }

    bool check(int val, int s, int k) {
        for (int x = 0; x <= k; ++x) {
            int l1 = s - x, r1 = s + max(0, k - 2 * x);
            if (get(l1, r1) >= val) return true;

            int r2 = s + x, l2 = s - max(0, k - 2 * x);
            if (get(l2, r2) >= val) return true;
        }
        return false;
    }

    int maxTotalFruits(vector<vector<int>>& f, int s, int k) {
        
        // 2 cases
        // go left x and go right k - 2*x
        // go right x and go left k-2*x
        // maximium of this two
        // use binary search for finding x
        
        int n = f.size();
        p.resize(n);
        pre.resize(n + 1);
        for (int i = 0; i < n; ++i) {
            p[i] = f[i][0];
            pre[i + 1] = pre[i] + f[i][1];
        }

        int lo = 0, hi = pre[n], ans = 0;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (check(mid, s, k)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};
