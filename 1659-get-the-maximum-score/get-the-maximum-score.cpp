class Solution {
public:
    long long maxSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        int n = nums1.size();
        int m = nums2.size();
        int i = 0, j = 0;
        long long ans = 0;
        long long mod = 1e9+7;
        while (i < n && j < m) {
            while (i < n && j < m && nums1[i] < nums2[j]) {
                sum1 += nums1[i];
                i++;
            }
            while (i < n && j < m && nums2[j] < nums1[i]) {
                sum2 += nums2[j];
                j++;
            }
            if (i < n && j < m && nums1[i] == nums2[j]) {
                ans += max(sum1, sum2) + nums1[i];
                sum1 = 0;
                sum2 = 0;
                i++;
                j++;
            }
        }
        while (i < n) {
            sum1 += nums1[i];
            i++;
        }
        while (j < m) {
            sum2 += nums2[j];
            j++;
        }
        ans += max(sum1, sum2);
        return ans%mod;
    }
};