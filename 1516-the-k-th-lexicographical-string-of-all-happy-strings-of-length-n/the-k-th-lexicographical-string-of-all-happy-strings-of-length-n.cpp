class Solution {
public:
    vector<string> ans;

    void backtrack(int idx, int n, int k, vector<char> &c, string curr, char prev) {
        if (curr.size() == n) {
            ans.push_back(curr);
            return;
        }

        if (ans.size() >= k)
            return;

        for (int i = 0; i < 3; i++) {
            if (c[i] != prev) {
                backtrack(idx + 1, n, k, c, curr + c[i], c[i]);
            }
        }
    }

    string getHappyString(int n, int k) {
        vector<char> c = {'a', 'b', 'c'};
        backtrack(0, n, k, c, "", '/');  // '/' is a dummy char not in {'a','b','c'}
        
        if (k <= ans.size())
            return ans[k - 1];

        return "";
    }
};
