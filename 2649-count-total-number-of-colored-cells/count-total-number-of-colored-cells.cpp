class Solution {
public:
    long long coloredCells(int n) {
        long long ans  = n;
        ans*=ans;
        if(n==1)
        return 1;
        ans=ans*2-n*2+1;

        return ans;
    }
};