class Solution {
public:
    int integerReplacement(int n) {
        long long m = n;
        int c = 0;
        if (m == 1)
            return 0;
        while (m > 1) {
            while (m % 2 == 0) {
                m =m / 2;
                c++;
            }
            if (m == 3) {
                c = c + 2;
                return c;
            }
            if (m == 1) {
                return c;
            }

            int next =m + 1;
            if (next % 4 == 0) {
                c++;
                m = m + 1;
            } else {
                m = m - 1;
                c++;
            }
        }
        return c;
    }
};