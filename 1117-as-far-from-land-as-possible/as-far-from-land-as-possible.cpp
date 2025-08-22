class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dis(n, vector<int>(m, -1));
        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    dis[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        if (q.empty() || q.size() == n*m) return -1;

        int dx[4]={0,0,1,-1}, dy[4]={1,-1,0,0};
        int ans = -1;

        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();

            for(int k=0;k<4;k++){
                int nx = x+dx[k], ny = y+dy[k];
                if(nx>=0 && ny>=0 && nx<n && ny<m && dis[nx][ny]==-1){
                    dis[nx][ny] = dis[x][y] + 1;
                    ans = max(ans, dis[nx][ny]);
                    q.push({nx,ny});
                }
            }
        }
        return ans;
    }
};
