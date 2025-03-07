class Solution {
public:
    vector<long long> segmentedSieve(long long L, long long R) {
        long long lim = sqrt(R);
        vector<char> mark(lim + 1, false);
        vector<long long> primes;

        for (long long i = 2; i <= lim; ++i) {
            if (!mark[i]) {
                primes.push_back(i);
                for (long long j = i * i; j <= lim; j += i)
                    mark[j] = true;
            }
        }

        vector<char> isPrime(R - L + 1, true);
        for (long long i : primes) {
            for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
                isPrime[j - L] = false;
        }
        if (L == 1)
            isPrime[0] = false;

        vector<long long> primeNumbers;
        for (long long i = 0; i < R - L + 1; ++i)
            if (isPrime[i])
                primeNumbers.push_back(L + i);

        return primeNumbers;
    }

    vector<int> closestPrimes(int left, int right) {
        vector<long long> v = segmentedSieve(left, right);
        if (v.size() < 2) return {-1, -1};

        int a = -1, b = -1, diff = INT_MAX;
        for (size_t i = 0; i < v.size() - 1; i++) {
            int t = v[i+1] - v[i];
            if (t < diff) {
                diff = t;
                a = v[i];
                b = v[i+1];
            }
        }
        return {a, b};
    }
};
