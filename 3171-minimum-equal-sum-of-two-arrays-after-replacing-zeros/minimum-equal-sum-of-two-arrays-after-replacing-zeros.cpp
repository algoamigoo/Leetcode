class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        
        long long zeroCount1 = 0;
        long long sum1 = 0;
        long long zeroCount2 = 0;
        long long sum2 = 0;

        for(auto num : nums1) {
            if(num == 0) {
                zeroCount1++;
            }
            sum1 += num;
        }

        for(auto num : nums2) {
            if(num == 0) {
                zeroCount2++;
            }
            sum2 += num;
        }

        long long minSum1 = sum1 + zeroCount1;
        long long maxSum1 = zeroCount1 > 0 ? LLONG_MAX : sum1;

        long long minSum2 = sum2 + zeroCount2;
        long long maxSum2 = zeroCount2 > 0 ? LLONG_MAX : sum2;

        long long minSum = max(minSum1, minSum2);

        if(minSum <= maxSum1 && minSum <= maxSum2) {
            return minSum;
        }

        return -1;
    }
};
