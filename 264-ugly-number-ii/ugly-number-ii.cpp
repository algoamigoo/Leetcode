class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> primes = {2, 3, 5};
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        unordered_set<long long> seen;

        pq.push(1);
        seen.insert(1);

        long long ugly = 1;

        for (int i = 0; i < n; i++) {
            ugly = pq.top();
            pq.pop();

            for (int p : primes) {
                long long next = ugly * p;
                if (!seen.count(next)) {
                    seen.insert(next);
                    pq.push(next);
                }
            }
        }

        return (int)ugly;
    }
};
