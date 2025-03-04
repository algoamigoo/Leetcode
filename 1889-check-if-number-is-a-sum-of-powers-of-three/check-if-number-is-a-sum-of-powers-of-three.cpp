#include <vector>
#include <algorithm>

class Solution {
public:
    bool checkPowersOfThree(int n) {
        vector<int> v;
        for (int i = 1; i <= n; i *= 3) {
            v.push_back(i);
        }
        for (int i = v.size() - 1; i >= 0; --i) {
            if (n >= v[i]) {
                n -= v[i];
            }
            if (n == 0) {
                return true;
            }
        }
        
        return false;
    }
};