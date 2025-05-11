class Solution {
public:
    long long power(long long base, long long exp, int mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

    long long modInverse(long long n, int mod) {
        return power(n, mod - 2, mod);
    }

    vector<vector<vector<int>>> mem;
    int dp(int idx, int sum, int nums_count_allowed, string &num) {
        int mod = 1e9+7;
        if (sum == 0 && nums_count_allowed == 0) return 1;
        if (nums_count_allowed <= 0 || sum < 0 || idx < 0) return 0;
        if (mem[idx][sum][nums_count_allowed] != -1) return mem[idx][sum][nums_count_allowed];

        int skip = dp(idx - 1, sum, nums_count_allowed, num);

        int currentNum = num[idx] - '0';
        int choose = false;
        if (currentNum <= sum) {
            choose = dp(idx - 1, sum - currentNum, nums_count_allowed - 1, num);
        }

        return mem[idx][sum][nums_count_allowed] = (skip + choose) % mod;
    }

    int countBalancedPermutations(string num) {
        int sum = 0;
        for (char chr : num) {
            sum += (chr - '0');
        }

        if (sum % 2 != 0) return 0;

        int req = sum / 2;
        int nums_count_allowed = num.size() / 2;
        int n = num.size();

        mem.assign(n, vector<vector<int>>(req + 1, vector<int>(nums_count_allowed + 1, -1)));

        int total_ways = dp(n - 1, req, nums_count_allowed, num);
        if (!total_ways) return 0;

        unordered_map<int, int> umap;
        for (char i : num) umap[i - '0']++;

        int mod = 1e9 + 7;
        vector<long long> factorial(n + 1, 1);
        for (int i = 2; i <= n; i++) {
            factorial[i] = (factorial[i - 1] * i) % mod;
        }

        long long ans = (total_ways * ((1LL * factorial[nums_count_allowed] * factorial[n - nums_count_allowed]) % mod) % mod);

        for (auto &[_, freq] : umap) {
            ans = (ans * modInverse(factorial[freq], mod)) % mod;
        }

        return ans;
    }
};