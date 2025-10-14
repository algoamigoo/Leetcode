class Solution {
public:
    int memo[50001];
    int n;
    
    // Binary search: find first job with start >= current job's end
    int func(vector<vector<int>>& array, int l, int currentJobEnd) {
        int r = n - 1;
        int result = n; // not n+1
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (array[mid][0] >= currentJobEnd) {
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return result;
    }
    
    int solve(vector<vector<int>>& array, int i) {
        if (i >= n)
            return 0;
        if (memo[i] != -1)
            return memo[i];
        
        int next = func(array, i + 1, array[i][1]);
        int taken = array[i][2] + solve(array, next);
        int notTaken = solve(array, i + 1);
        
        return memo[i] = max(taken, notTaken);
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n = startTime.size();
        memset(memo, -1, sizeof(memo));
        
        vector<vector<int>> array(n, vector<int>(3));
        for (int i = 0; i < n; i++) {
            array[i][0] = startTime[i];
            array[i][1] = endTime[i];
            array[i][2] = profit[i];
        }
        
        sort(array.begin(), array.end(), [](auto& a, auto& b) {
            return a[0] < b[0]; 
        });
        
        return solve(array, 0);
    }
};
