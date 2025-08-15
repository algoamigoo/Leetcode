class Solution {
public:
    int arrangeCoins(int n) {
        // 1 3 6 10 ........ 2^30
        long long l = 1;
        long long r = n;
        while(l <= r){
			long mid = l + (r - l) / 2;
			long used = mid * (mid + 1)/2;
			if(used == n){
				return (int)mid;
			}
			if(n < used){
				r = mid-1;
			}
			else{
				l = mid + 1;
			}
		}
		return (int)r;
    }
};