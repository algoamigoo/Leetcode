class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        
        for(int i=0; i<=60; i++){
            long long k = num1 - ((long long)i*num2);
            if(k<0) continue;
            int stbit = __builtin_popcountll(k);
            if(stbit <= i && i <= k) return i;
        }

        return -1;
    }
};