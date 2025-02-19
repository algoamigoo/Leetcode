class Solution {
public:
    int n;
    
    bool canDistribute(vector<int>& cookies, vector<int>& children, int idx, int maxCookies) {
        if (idx == n) return true;
        
        for (int i = 0; i < children.size(); i++) {
            if (children[i] + cookies[idx] <= maxCookies) {
                children[i] += cookies[idx];
                if (canDistribute(cookies, children, idx + 1, maxCookies)) return true;
                children[i] -= cookies[idx];

                if (children[i] == 0) break; // Prune duplicate states
            }
        }
        
        return false;
    }

    int minimumTimeRequired(vector<int>& cookies, int k) {
        n = cookies.size();
        sort(cookies.rbegin(), cookies.rend());
        int l = cookies[0], r = accumulate(cookies.begin(), cookies.end(), 0), ans = r;
        while (l <= r) {
            int mid = (l + r) / 2;
            vector<int> children(k, 0);

            if (canDistribute(cookies, children, 0, mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        return ans;
    }
};
