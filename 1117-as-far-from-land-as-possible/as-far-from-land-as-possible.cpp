class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dis(n,vector<int>(m,-1));
        // dont need visited, just see if dis set to -1 or not

        queue<pair<int,int>> q;
        // queue all the land cell coordinates
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    dis[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        // now i will traverse from all the queued nodes until my queue is empty
        // make a new grid storing the distances from the land nodes
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        int s = 1;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto [x,y]=q.front();
                q.pop();
                for(int k=0;k<4;k++){
                    int nx = x+dx[k];
                    int ny = y+dy[k];
                    
                    if(nx>=0 && ny>=0 && nx<n && ny<m && dis[nx][ny]==-1){
                        dis[nx][ny]=s;
                        q.push({nx,ny});
                    }
                }
            }
            s++;
        }


        // at last iterate through all the nodes
        // check for grid[i][j]==0 and track the minimum and that my answer
        int ans= INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    ans=max(ans,dis[i][j]);
                }
            }
        }
        if(ans==INT_MIN)
        return -1;
        
        return ans;
    }
};