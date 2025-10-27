class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        long long ans=0;
        int n = nums1.size();
        int last = INT_MAX;
        for(int i=0;i<n;i++){
            if (max (nums1[i], nums2[i]) >= nums2.back() && 
            min (nums1[i], nums2[i]) <= nums2.back())
            last = 1;
            last = min (last, 1 + min (abs (nums1[i] - nums2.back()), 
            abs (nums2[i] - nums2.back())));
            ans+=abs(nums2[i] - nums1[i]);
        }
        ans+=last;
        return ans;
    }
};