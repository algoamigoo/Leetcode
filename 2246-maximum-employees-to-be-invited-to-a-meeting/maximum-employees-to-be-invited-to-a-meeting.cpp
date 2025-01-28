class Solution {
public:
    int bfs(int start, unordered_map<int, vector<int>>& adj, vector<bool>& vis2) {
        queue<pair<int, int>> q;
        q.push({start, 0});
        int maxDepth = 0;
        vis2[start] = true;
        
        while (!q.empty()) {
            int curr = q.front().first;
            int depth = q.front().second;
            q.pop();
            
            for (int neighbor : adj[curr]) {
                if (!vis2[neighbor]) {
                    vis2[neighbor] = true;
                    q.push({neighbor, depth + 1});
                    maxDepth = max(maxDepth, depth + 1);
                }
            }
        }
        return maxDepth;
    }
    
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        
        // Build reverse graph for finding chains
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < n; i++) {
            adj[favorite[i]].push_back(i);
        }
        
        vector<bool> vis(n, false);
        int maxCycleLen = 0;  // For case 1: longest cycle
        int totalChainLen = 0;  // For case 2: sum of mutual pairs + their chains
        
        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            
            vector<int> cycle;
            int curr = i;
            
            // Find cycle
            while (!vis[curr]) {
                vis[curr] = true;
                cycle.push_back(curr);
                curr = favorite[curr];
            }
            
            // Find where cycle starts
            int cycleStart = curr;
            int cycleLen = 0;
            bool isCycle = false;
            
            for (int j = 0; j < cycle.size(); j++) {
                if (cycle[j] == cycleStart) {
                    cycleLen = cycle.size() - j;
                    isCycle = true;
                    break;
                }
            }
            
            if (isCycle) {
                if (cycleLen == 2) {
                    // Case 2: Mutual pairs
                    int u = cycle[cycle.size() - 2];
                    int v = cycle[cycle.size() - 1];
                    vector<bool> vis2(n, false);
                    vis2[u] = vis2[v] = true;
                    totalChainLen += 2 + bfs(u, adj, vis2) + bfs(v, adj, vis2);
                } else {
                    // Case 1: Longer cycle
                    maxCycleLen = max(maxCycleLen, cycleLen);
                }
            }
        }
        
        return max(maxCycleLen, totalChainLen);
    }
};