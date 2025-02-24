class Solution {
public:
    // Step 1: Compute Bob's distances to node 0 using BFS, tracing path from bob to root
    void computeBobDistBFS(int bob, vector<vector<int>>& adj, vector<int>& bobDist) {
        int n = adj.size();
        queue<int> q;
        vector<int> parent(n, -1);

        q.push(bob);
        bobDist[bob] = 0;
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            if (node == 0) break;
            
            for (int neighbor : adj[node]) {
                if (bobDist[neighbor] == -1) {
                    bobDist[neighbor] = bobDist[node] + 1;
                    parent[neighbor] = node;
                    q.push(neighbor);
                }
            }
        }

        // Reset bobDist to only include nodes on Bob's path to node 0
        vector<int> tempDist(n, -1);
        int curr = 0;
        while (curr != -1) {
            tempDist[curr] = bobDist[curr];
            curr = parent[curr];
        }
        bobDist = tempDist;
    }

    // Step 2: DFS to find Alice's maximum profit
    int dfsAlice(int node, int parent, int aliceDist, vector<vector<int>>& adj, vector<int>& amount, vector<int>& bobDist) {
        int income = 0;
        if (bobDist[node] == -1 || aliceDist < bobDist[node]) {
            // Alice arrives before Bob or Bob never reaches this node
            income = amount[node];
        } else if (aliceDist == bobDist[node]) {
            // Alice and Bob arrive simultaneously, split cost/reward
            income = amount[node] / 2;
        }
        // If Alice arrives after Bob, income is 0 (gate already opened)

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

        // Return total profit: income at this node + max profit from children (if any)
        return income + (isLeaf ? 0 : maxChildProfit);
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        
        // Build the undirected tree graph
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Initialize Bob's distance array
        vector<int> bobDist(n, -1);

        // Section 1: Compute Bob's distances to node 0 using BFS
        computeBobDistBFS(bob, adj, bobDist);

        // Section 2: Run DFS from Alice's starting point (node 0) to maximize profit
        return dfsAlice(0, -1, 0, adj, amount, bobDist);
    }
};