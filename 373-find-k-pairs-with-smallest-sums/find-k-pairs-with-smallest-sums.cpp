class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> ans;
        if (n == 0 || m == 0 || k == 0) return ans;

        // Binary search over possible sums
        int low = nums1[0] + nums2[0];
        int high = nums1.back() + nums2.back();

        // Helper: count pairs with sum <= mid
        auto countPairs = [&](int mid) {
            long long cnt = 0;
            int j = m - 1;
            for (int i = 0; i < n; i++) {
                // move j while sum > mid
                while (j >= 0 && nums1[i] + nums2[j] > mid)
                    j--;
                cnt += (j + 1);
            }
            return cnt;
        };

        // Binary search for smallest sum threshold
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (countPairs(mid) >= k)
                high = mid;
            else
                low = mid + 1;
        }
        int targetSum = low;

        // Collect all pairs with sum < targetSum
        int j = m - 1;
        for (int i = 0; i < n; i++) {
            while (j >= 0 && nums1[i] + nums2[j] >= targetSum)
                j--;
            for (int t = 0; t <= j; t++) {
                ans.push_back({nums1[i], nums2[t]});
                if ((int)ans.size() == k) return ans;
            }
        }

        // Collect pairs with sum == targetSum
        for (int i = 0; i < n; i++) {
            for (int t = 0; t < m; t++) {
                if (nums1[i] + nums2[t] == targetSum) {
                    ans.push_back({nums1[i], nums2[t]});
                    if ((int)ans.size() == k) return ans;
                }
            }
        }

        return ans;
    }
};
