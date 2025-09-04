class Solution {
public:
    vector<int> merge(vector<int> &v1, vector<int> &v2) {
        vector<int> ans;
        int i = 0, j = 0;
        while (i < v1.size() && j < v2.size()) {
            if (v1[i] <= v2[j]) {
                ans.push_back(v1[i]);
                i++;
            } else {
                ans.push_back(v2[j]);
                j++;
            }
        }
        
        while (i < v1.size()) ans.push_back(v1[i++]);
        while (j < v2.size()) ans.push_back(v2[j++]);
        return ans;
    }

    vector<int> mergesort(int start, int end, vector<int> &nums) {
        if (start == end) return {nums[start]};
        
        int mid = (start + end) / 2;
        vector<int> v1 = mergesort(start, mid, nums);
        vector<int> v2 = mergesort(mid + 1, end, nums);

        return merge(v1, v2);
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        return mergesort(0, n - 1, nums);
    }
};
