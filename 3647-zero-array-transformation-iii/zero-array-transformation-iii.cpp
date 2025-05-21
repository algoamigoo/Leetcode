class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) return b[1] < a[1];
        return a[0] < b[0];
    }

    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), q = queries.size();
        sort(queries.begin(), queries.end(), cmp);

        priority_queue<int> maxpq;
        priority_queue<int, vector<int>, greater<int>> minpq;

        int j = 0;
        for (int i = 0; i < n; ++i) {
            while (j < q && queries[j][0] == i) {
                maxpq.push(queries[j][1]);
                j++;
            }
            while (!minpq.empty() && minpq.top() < i) {
                minpq.pop();
            }
            while ((int)minpq.size() < nums[i]) {
                if (maxpq.empty() || maxpq.top() < i) return -1;
                minpq.push(maxpq.top());
                maxpq.pop();
            }
        }

        return maxpq.size();
    }
};
