class Solution {
public:
    int n, ans;
    
    void backtrack(int idx, vector<int>& cookies, vector<int>& children, int k) {
        if (idx == n) {
            ans = min(ans, *max_element(children.begin(), children.end()));
            return;
        }
        
        for (int i = 0; i < k; i++) {  
            children[i] += cookies[idx];
            backtrack(idx + 1, cookies, children, k);
            children[i] -= cookies[idx];

            if (children[i] == 0) break;
        }
    }
    int minimumTimeRequired(vector<int>& cookies, int k) {
        
        n = cookies.size();
        ans = INT_MAX;
        vector<int> children(k, 0);
        backtrack(0, cookies, children, k);
        return ans;
    }
};