class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        int z1 = 0, z2 = 0;
        
        // Calculate sum and count zeros for nums1
        for (int num : nums1) {
            sum1 += num;
            if (num == 0) z1++;
        }
        
        // Calculate sum and count zeros for nums2
        for (int num : nums2) {
            sum2 += num;
            if (num == 0) z2++;
        }
    
        long long minSum1 = sum1 + z1;
        long long minSum2 = sum2 + z2;
        
        if (z1 == 0 && z2 == 0) {
            if (sum1 != sum2) return -1;
            return sum1;
        } else if (z1 == 0) {
            if (sum1 < minSum2) return -1; 
            return sum1;
        } else if (z2 == 0) {
            if (sum2 < minSum1) return -1; 
            return sum2;
        } else {
            return max(minSum1, minSum2);
        }
    }
};