class Solution {
public:
    void backtrack(vector<int>& in, vector<vector<int>>& req, 
                  int i, int curr, int& mx) {
        // Base case: reached end of requests
        if (i == req.size()) {
            // Check if all buildings have zero net change
            for (int degree : in) {
                if (degree != 0) 
                return;
            }
            mx = max(mx, curr);
            return;
        }
        backtrack(in, req, i + 1, curr, mx);
        
        in[req[i][0]]--;
        in[req[i][1]]++; 
        
        backtrack(in, req, i + 1, curr+1, mx);
        
        in[req[i][0]]++;
        in[req[i][1]]--; 
    }
    
    int maximumRequests(int n, vector<vector<int>>& req) {
        vector<int> in(n, 0);
        int mx = 0;
        backtrack(in, req, 0, 0, mx);
        return mx;
    }
};