class Solution {
public:
    vector<vector<int>> ans;

    void backtrack(int i, int n, int k, vector<int> temp) {
        if (temp.size() == k) {
            ans.push_back(temp);
            return;
        }

        if (i > n || temp.size() + (n - i + 1) < k)
            return;

        temp.push_back(i);
        backtrack(i + 1, n, k, temp);
        temp.pop_back();
        backtrack(i + 1, n, k, temp);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        backtrack(1, n, k, temp);
        return ans;
    }
};
