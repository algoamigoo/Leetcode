class Solution {
public:
    int numWaterBottles(int n, int x) {
        int drank =n;
        int rem=0;
        while(n>=x){
            rem=n%x;
            n=n/x;
            drank+=n;
            n=(n+rem);

        }
        return drank;
    }
};