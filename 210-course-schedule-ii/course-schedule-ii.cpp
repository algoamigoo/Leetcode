class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        int m = prerequisites.size();
        vector<vector<int>> adj(n); // adj list
        vector<int> indegree(n, 0); // indegrees

        for (int i = 0; i < m; i++) {
            int x = prerequisites[i][0];
            int y = prerequisites[i][1];
            adj[y].push_back(x);
            indegree[x]++;
        }

        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> order; // indegrees 0 1
        order.reserve(n);

        while (!q.empty()) {
            int p = q.front();
            q.pop();
            order.push_back(p);

            for (auto it : adj[p]) {
                if (--indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        
            if (order.size() == n)
                return order;

            return {};
    }
};