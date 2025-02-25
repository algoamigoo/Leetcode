class Solution {
public:
    void backtrack(vector<int>& indegrees, vector<vector<int>>& requests, 
                  int index, int currCount, int& maxRequests) {
        // Base case: reached end of requests
        if (index == requests.size()) {
            // Check if all buildings have zero net change
            for (int degree : indegrees) {
                if (degree != 0) return;
            }
            maxRequests = max(maxRequests, currCount);
            return;
        }
        backtrack(indegrees, requests, index + 1, currCount, maxRequests);
        
        indegrees[requests[index][0]]--;
        indegrees[requests[index][1]]++; 
        backtrack(indegrees, requests, index + 1, currCount + 1, maxRequests);
        
        indegrees[requests[index][0]]++;
        indegrees[requests[index][1]]--;
    }
    
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> indegrees(n, 0);
        int maxRequests = 0;
        backtrack(indegrees, requests, 0, 0, maxRequests);
        return maxRequests;
    }
};