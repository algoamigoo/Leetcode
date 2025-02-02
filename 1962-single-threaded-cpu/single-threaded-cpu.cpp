class Solution {
public:
    static bool comp(const vector<long long>& a, const vector<long long>& b) {
        if (a[0] == b[0]) {
            return a[1] < b[1];
        }
        return a[0] < b[0];
    }

    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<vector<long long>> v; // enter time, processing time, index
        int n = tasks.size();
        for (int i = 0; i < n; i++) {
            v.push_back({tasks[i][0], tasks[i][1], i});
        }
        sort(v.begin(), v.end(), comp);
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> q;
        vector<int> ans;
        long long i = 0, time = 0;

        while (i < n || !q.empty()) {
            while (i < n && v[i][0] <= time) {
                q.push({v[i][1], v[i][2]});
                i++;
            }

            if (!q.empty()) {
                auto [proc_time, index] = q.top();
                q.pop();
                time += proc_time;
                ans.push_back(index);
            } else {
                time = v[i][0];
            }
        }

        return ans;
    }
};
