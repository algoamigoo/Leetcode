class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start;
        for (auto &row : board)
            for (int x : row)
                start += char('0' + x);

        string target = "123450";

        // adjacency list for each index
        vector<vector<int>> adj = {
            {1,3},    // 0
            {0,2,4},  // 1
            {1,5},    // 2
            {0,4},    // 3
            {1,3,5},  // 4
            {2,4}     // 5
        };

        queue<pair<string,int>> q; // state, steps
        unordered_set<string> vis;

        q.push({start, 0});
        vis.insert(start);

        while (!q.empty()) {
            auto [cur, steps] = q.front();
            q.pop();

            if (cur == target)
                return steps;

            int zeroPos = cur.find('0');
            for (int nei : adj[zeroPos]) {
                string nxt = cur;
                swap(nxt[zeroPos], nxt[nei]);
                if (!vis.count(nxt)) {
                    vis.insert(nxt);
                    q.push({nxt, steps + 1});
                }
            }
        }
        return -1;
    }
};
