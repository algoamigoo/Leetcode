class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size();     // rows
        int m = mat[0].size();  // columns
        
        // Create prefix sum array with extra column
        vector<vector<int>> prefix(n + 1, vector<int>(m + 1, 0));
        
        // Build prefix sum array
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                prefix[i][j] = mat[i-1][j-1] + prefix[i-1][j] + 
                              prefix[i][j-1] - prefix[i-1][j-1];
            }
        }
        
        int maxSide = 0;
        int maxPossible = min(n, m);  // Maximum possible square size
        
        // Check all possible square sizes
        for(int side = 1; side <= maxPossible; side++) {
            for(int i = side; i <= n; i++) {
                for(int j = side; j <= m; j++) {
                    // Calculate sum of square with top-left at (i-side, j-side)
                    int sum = prefix[i][j] - 
                             prefix[i-side][j] - 
                             prefix[i][j-side] + 
                             prefix[i-side][j-side];
                    
                    if(sum <= threshold) {
                        maxSide = max(maxSide, side);
                    }
                }
            }
        }
        
        return maxSide;
    }
};