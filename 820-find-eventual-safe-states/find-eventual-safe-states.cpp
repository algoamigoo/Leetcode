class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> outdegree(n);
        vector<vector<int>> reversed_graph(n);
        for (int i = 0; i < n; i++) {
            outdegree[i] = graph[i].size();
            for (int j : graph[i]) {
                reversed_graph[j].push_back(i);
            }
        }
        
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (outdegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<bool> safe(n, false);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safe[node] = true;
            
            for (int prev : reversed_graph[node]) {
                outdegree[prev]--;
                if (outdegree[prev] == 0) {
                    q.push(prev);
                }
            }
        }
        
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (safe[i]) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};