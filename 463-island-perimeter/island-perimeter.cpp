class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(grid[i][j]==1){
                    int dx[4]={0,0,1,-1};
                    int dy[4]={1,-1,0,0};
                    for(int d=0;d<4;d++){
                        int nx=i+dx[d];
                        int ny=j+dy[d];
                        if(nx<0 || ny<0 || nx>=n || ny>=m || grid[nx][ny]==0)
                        c++;
                    }
                }

            }
        }
        return c;
    }
};