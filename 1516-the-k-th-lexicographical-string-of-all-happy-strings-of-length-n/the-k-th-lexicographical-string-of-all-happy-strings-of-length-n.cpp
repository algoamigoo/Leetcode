class Solution {
public:
    vector<string> ans;

    void backtrack(int n, int k, string curr) {
        if (curr.size() == n) {
            ans.push_back(curr);
            return;
        }

        if (ans.size() >= k) return;

        for (char ch : {'a', 'b', 'c'}) {
            if (curr.empty() || curr.back() != ch) {
                backtrack(n, k, curr + ch);
            }
        }
    }

    string getHappyString(int n, int k) {
        backtrack(n, k, "");
        if (k <= ans.size())
            return ans[k - 1];
        return "";
    }
};
