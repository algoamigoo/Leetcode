class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;   // num -> next greater
        stack<int> st;
        
        for (int i = 0; i < nums2.size(); i++) {
            while (!st.empty() && nums2[i] > st.top()) {
                mp[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        
        vector<int> res;
        for (int x : nums1) {
            res.push_back(mp.count(x) ? mp[x] : -1);
        }
        return res;
    }
};
