class Solution {
public:
    long long calc(long long mid, long long len) {
        if (mid > len) return (mid - 1 + mid - len) * len / 2;  
        //first term = mid - len last term = mid - 1 number of terms = len
        //Sum = (first + last) * len / 2
        return (mid - 1) * mid / 2 + (len - (mid - 1)); //There are (mid - 1) decreasing elements and (len - (mid - 1)) ones.
        //Sum of decreasing part = (mid - 1) * mid / 2
        //Sum of the remaining ones = len - (mid - 1)
    }

    long long func(int mid, int n, int i) {
        return calc(mid, i) + calc(mid, n - i - 1) + mid;
    }

    int maxValue(int n, int i, int maxSum) {
        int l = 1, r = maxSum, ans = 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (func(mid, n, i) <= maxSum) {
                ans = mid;
                l = mid + 1;
            } else r = mid - 1;
        }
        return ans;
    }
};
