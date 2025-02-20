class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for (int curr : asteroids) {
            bool exploded = false;
            while (!st.empty() && st.top() > 0 && curr < 0 && !exploded) {
                if (st.top() < abs(curr)) {
                    st.pop();
                    continue;
                }
                else if (st.top() == abs(curr)) {
                    st.pop();
                    exploded = true;
                }
                else {
                    exploded = true;
                }
            }
            if (!exploded) {
                st.push(curr);
            }
        }
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};