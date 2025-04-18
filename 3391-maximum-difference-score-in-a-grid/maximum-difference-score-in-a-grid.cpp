class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> a(n,vector<int>(m));
        a[0][0]=grid[0][0];
        for(int i=1;i<n;i++) a[i][0] = min(a[i-1][0],grid[i][0]); // first col
        for(int i=1;i<m;i++) a[0][i] = min(a[0][i-1],grid[0][i]); // first row
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                a[i][j] = min({a[i-1][j],a[i][j-1],grid[i][j]});
            }
        }
       
        int ans = INT_MIN;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                int b = INT_MAX;
                if(i-1>=0) b=min(b,a[i-1][j]);
                if(j-1>=0) b=min(b,a[i][j-1]);
                ans=max(ans,grid[i][j]-b);
            }
        }
        return ans;
    }
};