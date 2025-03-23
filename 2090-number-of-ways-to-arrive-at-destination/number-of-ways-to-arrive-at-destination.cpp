class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) { vector<pair<int, int>> adj[n];
        for (auto it : roads)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        // Defining a priority queue (min heap). 
        priority_queue<pair<long, long>,
                       vector<pair<long, long>>, greater<pair<long, long>>> pq;

        // Initializing the dist array and the ways array
        // along with their first indices.
        vector<long long> dist(n, 1e12), ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        long long mod = (1e9+7);

        while (!pq.empty())
        {
            long dis = pq.top().first;
            long node = pq.top().second;
            pq.pop();

            for (auto it : adj[node])
            {
                long long adjNode = it.first;
                long long edW = it.second;

                if (dis + edW < dist[adjNode])
                {
                    dist[adjNode] = dis + edW;
                    pq.push({dis + edW, adjNode});
                    ways[adjNode] = ways[node];
                }

                else if (dis + edW == dist[adjNode])
                {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        return ways[n - 1] % mod;
    }
};