class Solution {
public:
    bool isPerfectSquare(int n) {
     long long l = 1;
        long long r = n;
        while(l <= r){
			long mid = l + (r - l) / 2;
			long used = mid * (mid);
			if(used == n){
				return true;
			}
			if(n < used){
				r = mid-1;
			}
			else{
				l = mid + 1;
			}
		}
		return false;
    }
};