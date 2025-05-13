class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int MOD = 1e9 + 7;
        int n = s.size();
        vector<int> cc(26, 0);
        for (int i = 0; i < n; ++i) {
            cc[s[i] - 'a']++;
        }
        for (int _ = 0; _ < t; _++) {
            vector<int> nc(26, 0);
            for (int i = 0; i < 26; ++i) {
                if (i < 25) {
                    nc[i + 1] = (nc[i + 1] + cc[i]) % MOD;
                } else {
                    for(int j=0;j<2;j++)
                    nc[j] = (nc[j] + cc[i]) % MOD;
                }
            }
            cc = nc;
        }

        int ans = 0;
        for (auto it  : cc) {
            ans = (ans + it) % MOD;
        }
        return ans;
    }
};