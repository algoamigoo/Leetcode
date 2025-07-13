class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n,0);
        for(int i=0;i<edges.size();i++){
            indegree[edges[i][1]]++;
        }
        int ans=0;
        int f=0;
        for(int i=0;i<n;i++){
            
            if(indegree[i]==0 && f==1)
            return -1;
            if(indegree[i]==0 && f==0)
            {ans=i;
            f=1;}
        }
        return ans;
    }
};