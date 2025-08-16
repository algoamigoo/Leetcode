class Solution {
public:
    int r,c;
    int dfs(int i,int j,vector<vector<bool>>&vis,vector<vector<int>> &grid){
        if(i<0 || i>=r || j<0 || j>=c || vis[i][j] || grid[i][j]==0)
        return 0;

        vis[i][j]=true;

        return {1+dfs(i+1,j,vis,grid)
                  +dfs(i,j+1,vis,grid)
                  +dfs(i,j-1,vis,grid)
                  +dfs(i-1,j,vis,grid)};
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        r=rows;
        c=cols;
        vector<vector<bool>> vis(rows,vector<bool>(cols,false));

        int max_area=0;
        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                if(!vis[r][c] && grid[r][c]==1){
                    int area=dfs(r,c,vis,grid);
                    max_area=max(area,max_area);
                }
            }
        }
        return max_area;
    }
};