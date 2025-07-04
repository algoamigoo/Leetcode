class Solution {
public:
    unsigned long long binpow(unsigned long long a, unsigned long long b) {
        long long res = 1;
        while (b > 0) {
            if (b & 1)
                res = res * a;
            a = a * a;
            b >>= 1;
        }
        return res;
    }
    char kthCharacter(long long k, vector<int>& op) {
        int level = ceil(log2(k));
        op.resize(level);
        int n = op.size();
        long long ind = k;
        int x = 0;
        for (int i = n - 1; i >= 0; i--) {
            long long half = binpow(2, i);
            if (ind > half) {
                if (op[i] == 1) x++;
                ind -= half;
            }
        }
        cout << x << endl;
        return (x % 26) + 'a';
    }
};