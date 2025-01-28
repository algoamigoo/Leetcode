class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int m, int n) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it : edges){
            int a = it[0];
            int b=  it[1];
            int w = it[2];

            adj[a].push_back({b,w+1});
            adj[b].push_back({a,w+1});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int, int>>> pq;
        vector<int> dist(n,INT_MAX);
        dist[0]=0;
        pq.push({0,0});

        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(d>dist[node])
            continue;

            for (auto& [x, w] : adj[node]) {
                int newDist = d + w;
                if (newDist < dist[x]) {
                    dist[x] = newDist;
                    pq.push({newDist, x});
                }
            }
        }
        int ans=0;
        for(auto &x : dist){
            if(x<=m)
            ans+=1;
        }

        for (auto &x : edges) {
            int a = x[0], b = x[1], w = x[2];
            int froma = max(0, m - dist[a]);
            int fromb = max(0, m - dist[b]);
            ans += min(w, froma + fromb);
        }

        return ans;
    }
};