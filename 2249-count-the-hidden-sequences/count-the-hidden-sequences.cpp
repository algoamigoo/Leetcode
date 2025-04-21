class Solution {
public:
    int numberOfArrays(vector<int>& v, int lower, int upper) {
        long long x = 0,low=0,high=0;
        for(int i=0;i<v.size();i++){
            x+=v[i];
            low=min(low,x);
            high=max(high,x);
        }
        return max(0LL, upper - lower + low - high + 1);
    }
};