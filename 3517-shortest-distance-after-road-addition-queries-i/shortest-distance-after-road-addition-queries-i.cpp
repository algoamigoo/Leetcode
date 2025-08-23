class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < n-1; i++) {
            adj[i].push_back(i+1);   // default edges i -> i+1
        }

        vector<int> ans;
        for (auto& q : queries) {
            int u = q[0], v = q[1];
            adj[u].push_back(v);     // add query edge

            // BFS from 0 to n-1
            vector<int> dist(n, -1);
            queue<int> Q;
            Q.push(0);
            dist[0] = 0;

            while (!Q.empty()) {
                int node = Q.front();
                Q.pop();
                for (int nei : adj[node]) {
                    if (dist[nei] == -1) {
                        dist[nei] = dist[node] + 1;
                        Q.push(nei);
                    }
                }
            }
            ans.push_back(dist[n-1]);
        }
        return ans;
    }
};
