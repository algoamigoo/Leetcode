class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        stack<int> st; // store indices

        for (int i = 0; i < 2 * n; i++) {
            int num = nums[i % n];
            while (!st.empty() && num > nums[st.top()]) {
                result[st.top()] = num;
                st.pop();
            }
            if (i < n) st.push(i); // push only in first pass
        }
        return result;
    }
};
