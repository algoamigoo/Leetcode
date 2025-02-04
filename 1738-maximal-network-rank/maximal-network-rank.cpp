class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<int>> adj;
        
        // Create the adjacency list
        for(int i = 0; i < roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int maxRank = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int rank = adj[i].size() + adj[j].size();
                
                if(find(adj[i].begin(), adj[i].end(), j) != adj[i].end()) {
                    rank--;
                }
                
                maxRank = max(maxRank, rank);
            }
        }
        
        return maxRank;
    }
};
