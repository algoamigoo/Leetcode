class Solution {
public:
    vector<int> people;  // store number of representatives in each subtree

    int dfs(int node, int parent, vector<vector<int>> &adj) {
        int cnt = 1; // each node has 1 representative
        for (auto child : adj[node]) {
            if (child != parent) {
                cnt += dfs(child, node, adj);
            }
        }
        people[node] = cnt;  // store people count for this subtree
        return cnt;
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        vector<vector<int>> adj(n);

        for (auto &road : roads) {
            int u = road[0], v = road[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        people.assign(n, 0);
        dfs(0, -1, adj);

        long long ans = 0;
        for (int node = 1; node < n; node++) { 
            // every node except root must travel to parent
            ans += (people[node] + seats - 1) / seats;  // ceil(people/seats)
        }
        return ans;
    }
};
