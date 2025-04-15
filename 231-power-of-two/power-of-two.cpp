class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)
        return false;
        int x = ceil(double(log2(n)));
        int y = floor(double(log2(n)));
        if(x==y)
        return true;

        return false;
    }
};