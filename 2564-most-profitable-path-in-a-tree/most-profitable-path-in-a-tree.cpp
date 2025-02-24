class Solution {
public:
    vector<int> bobDist; // Stores Bob's distance to each node

    void markBobPath(int bob, vector<int>& parent) {
        int dist = 0;
        while (bob != -1) {
            bobDist[bob] = dist++;
            bob = parent[bob]; // Move Bob upwards
        }
    }

    int dfsAlice(int node, int parent, int aliceDist, vector<vector<int>>& adj, vector<int>& amount) {
        int income = 0;

        // Compute earnings at current node based on Alice's & Bob's arrival times
        if (bobDist[node] == -1 || aliceDist < bobDist[node]) {
            income = amount[node]; // Alice gets full reward
        } else if (aliceDist == bobDist[node]) {
            income = amount[node] / 2; // Split reward
        }

        int maxProfit = INT_MIN;
        bool isLeaf = true;

        for (int neighbor : adj[node]) {
            if (neighbor == parent) continue; // Avoid revisiting parent node

            isLeaf = false;
            maxProfit = max(maxProfit, dfsAlice(neighbor, node, aliceDist + 1, adj, amount));
        }

        return income + (isLeaf ? 0 : maxProfit);
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<vector<int>> adj(n);
        
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Step 1: Find Bob's path and mark distances
        vector<int> parent(n, -1);
        bobDist.assign(n, -1);

        // BFS to find parent of each node (used for backtracking Bob’s path)
        queue<int> q;
        q.push(0);
        parent[0] = -1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : adj[node]) {
                if (neighbor != parent[node]) {
                    parent[neighbor] = node;
                    q.push(neighbor);
                }
            }
        }

        // Step 2: Mark Bob's actual path (4 → 2 → 0)
        markBobPath(bob, parent);

        // DEBUG: Print Bob's Distance Array
        cout << "Bob's Distance: ";
        for (int i = 0; i < n; i++) cout << bobDist[i] << " ";
        cout << endl;

        // Step 3: Alice moves from node 0 to leaf nodes, maximizing net income
        return dfsAlice(0, -1, 0, adj, amount);
    }
};
