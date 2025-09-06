class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = original.size();
        const int INF = 1e9;

        vector<vector<long long>> dist(26, vector<long long>(26, INF));

        // distance to itself = 0
        for(int i=0;i<26;i++){
            dist[i][i]=0;
        }

        // fill edges
        for(int i=0;i<n;i++){
            int u = original[i]-'a';
            int v = changed[i]-'a';
            dist[u][v] = min(dist[u][v], (long long)cost[i]); 
        }

        // Floyd-Warshall
        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    if(dist[i][k] < INF && dist[k][j] < INF){
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        // cost summation
        long long ans=0;
        int m = source.size();
        for(int i=0;i<m;i++){
            int u = source[i]-'a';
            int v = target[i]-'a';
            if(u==v) continue;
            if(dist[u][v] == INF) return -1; // impossible
            ans += dist[u][v];
        }

        return ans;
    }
};
