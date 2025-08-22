class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges,
                                         vector<vector<int>>& blueEdges) {
        // basically bfs
        // one try with rbrbrb then with brbrbr

        // i need the graph first
        // make an adj list, with edge wt as 1 if its red and -1 if its blue

        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < redEdges.size(); i++) {
            int u = redEdges[i][0];
            int v = redEdges[i][1];
            adj[u].push_back({v, 1});
        }
        for (int i = 0; i < blueEdges.size(); i++) {
            int u = blueEdges[i][0];
            int v = blueEdges[i][1];
            adj[u].push_back({v, -1});
        }

        vector<int> distRed(n, -1), distBlue(n, -1);
        distRed[0] = distBlue[0] = 0;

        queue<pair<int, int>> q;
        q.push({0, 1});  // starting as if last was red
        q.push({0, -1}); // starting as if last was blue

        while (!q.empty()) {
            auto [u, color] = q.front();
            q.pop();
            int currDist = (color == 1 ? distRed[u] : distBlue[u]);

            for (auto [v, nextColor] : adj[u]) {
                if (nextColor != color) {
                    if (nextColor == 1 && distRed[v] == -1) {
                        distRed[v] = currDist + 1;
                        q.push({v, 1});
                    }
                    if (nextColor == -1 && distBlue[v] == -1) {
                        distBlue[v] = currDist + 1;
                        q.push({v, -1});
                    }
                }
            }
        }

        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++) {
            if (distRed[i] == -1)
                ans[i] = distBlue[i];
            else if (distBlue[i] == -1)
                ans[i] = distRed[i];
            else
                ans[i] = min(distRed[i], distBlue[i]);
        }
        return ans;
    }
};