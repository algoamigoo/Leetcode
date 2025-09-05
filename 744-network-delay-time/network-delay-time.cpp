class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto & it : times){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v,w});
        }

        vector<int> dist(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        dist[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            int d = pq.top().first;
            int point = pq.top().second;
            pq.pop();
            for(auto & it : adj[point]) {
                int nextPoint = it.first;
                int weight = it.second;
                if(d + weight < dist[nextPoint]) {
                    dist[nextPoint] = d + weight;
                    pq.push({dist[nextPoint], nextPoint});
                }
            }
        }
        int maxTime = 0;
        for(int i = 1; i <= n; i++) {
            if(dist[i] == INT_MAX)
                return -1;
            maxTime = max(maxTime, dist[i]);
        }
        return maxTime;
    }
};