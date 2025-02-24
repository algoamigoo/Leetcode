class Solution {
public:
    // Step 1: Build the adjacency list graph and compute Bob's distances
    void buildGraphAndBobDist(vector<vector<int>>& edges, int n, int bob, vector<vector<int>>& adj, vector<int>& bobDist) {
        // Build undirected graph
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Use BFS to find parent array for Bob's path to root (node 0)
        vector<int> parent(n, -1);
        queue<int> q;
        q.push(0);
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (int neighbor : adj[node]) {
                if (parent[neighbor] == -1 && neighbor != 0) { // Skip if already visited
                    parent[neighbor] = node;
                    q.push(neighbor);
                }
            }
        }

        // Trace Bob's path back to node 0 and mark distances
        int dist = 0;
        int curr = bob;
        while (curr != -1) {
            bobDist[curr] = dist++;
            curr = parent[curr];
        }
    }

    // Step 2: DFS to find Alice's maximum profit
    int dfsAlice(int node, int parent, int aliceDist, vector<vector<int>>& adj, vector<int>& amount, vector<int>& bobDist) {
        // Calculate income at current node
        int income = 0;
        if (bobDist[node] == -1 || aliceDist < bobDist[node]) {
            // Alice arrives before Bob or Bob never reaches here
            income = amount[node];
        } else if (aliceDist == bobDist[node]) {
            // Alice and Bob arrive simultaneously, split the cost/reward
            income = amount[node] / 2;
        }
        // If Alice arrives after Bob, income stays 0 (gate already opened by Bob)

        // Check if this is a leaf node
        bool isLeaf = true;
        int maxChildProfit = INT_MIN;
        
        // Explore all neighbors except parent
        for (int neighbor : adj[node]) {
            if (neighbor != parent) {
                isLeaf = false;
                int childProfit = dfsAlice(neighbor, node, aliceDist + 1, adj, amount, bobDist);
                maxChildProfit = max(maxChildProfit, childProfit);
            }
        }

        // If leaf node, return just the income at this node
        if (isLeaf) return income;
        
        // Otherwise, return income plus max profit from children
        return income + maxChildProfit;
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        
        // Initialize adjacency list and Bob's distance array
        vector<vector<int>> adj(n);
        vector<int> bobDist(n, -1); // -1 means Bob doesn't reach this node
        
        // Section 1: Build graph and compute Bob's distances to node 0
        buildGraphAndBobDist(edges, n, bob, adj, bobDist);

        // Section 2: Run DFS from Alice's starting point (node 0) to maximize profit
        return dfsAlice(0, -1, 0, adj, amount, bobDist);
    }
};