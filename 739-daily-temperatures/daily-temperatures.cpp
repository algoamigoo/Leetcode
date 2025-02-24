class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& v) {
        int n = v.size();
        vector<int> ans(n, 0);
        stack<pair<int, int>> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && v[i] > st.top().first) {
                int indx = st.top().second;
                st.pop();
                ans[indx] = i - indx;
            }
            st.push({v[i], i});
        }
        return ans;
    }
};
