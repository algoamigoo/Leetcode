class Solution {
public:
    long long flowerGame(int n, int m) {
        long odd1 = (n+1)/2;
        long odd2 = (m+1)/2;
        long even1 = n/2;
        long even2 = m/2;

        return odd2*even1 + even2*odd1;
    }
};