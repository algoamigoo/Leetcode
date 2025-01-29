class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    
    int find(int x) {
        if(parent[x] == x)
            return x;
        
        return parent[x] = find(parent[x]);
    }
    
    void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);
 
    
        if(rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if(rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i = 1; i<=n; i++)
	    parent[i] = i;

        for(int i=0;i<n;i++){
                int x = edges[i][0];
                int y = edges[i][1];
                if(find(x)==find(y))
                return {x,y};
                else
                Union(x,y);
            }
    return {-1};
    }      
};