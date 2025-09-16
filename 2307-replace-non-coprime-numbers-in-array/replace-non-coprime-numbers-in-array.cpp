class Solution {
public:
    int gcd(int a, int b) {
        while (b) {
            int tmp = a % b;
            a = b;
            b = tmp;
        }
        return a;
    }

    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }

    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ans;

        for (int num : nums) {
            long long curr = num;

            while (!ans.empty()) {
                long long g = gcd(ans.back(), curr);
                if (g == 1) break;
                curr = lcm(ans.back(), curr);
                ans.pop_back();
            }

            ans.push_back((int)curr);
        }

        return ans;
    }
};
