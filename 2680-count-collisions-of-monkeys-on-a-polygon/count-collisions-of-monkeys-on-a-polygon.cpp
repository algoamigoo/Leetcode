class Solution {
public:
    long long mod = 1e9 + 7;

    int binpow(int a, int b, long long mod) {
        if (b == 0)
            return 1;

        long long half = binpow(a, b / 2, mod);
        if (b % 2 == 0) {
            return (half * half) % mod;
        } else {
            return (a * half % mod * half % mod) % mod;
        }
    }

    int monkeyMove(int n) { 
        return (binpow(2, n, mod) - 2 + mod) % mod; 
    }
};
