class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[1] < b[1])
            return true;
        if (a[1] == b[1])
            return a[0] < b[0];
        return false;
    }

    int maxEvents(vector<vector<int>>& v) {
        sort(v.begin(), v.end(), cmp);
        int n = v.size();
        int days = v[n - 1][1];

        set<int> s;
        for (int i = 1; i <= days; i++)
            s.insert(i);

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int l = v[i][0], r = v[i][1];
            auto it = s.lower_bound(l);
            if (it != s.end() && *it <= r) {
                cnt++;
                s.erase(it);
            }
        }

        return cnt;
    }
};
