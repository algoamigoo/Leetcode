class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dir = {{0,0}, {0,1}, {0,-1}, {1,0}, {-1,0}};
        
        auto isValid = [&](int r, int c) {
            return r >= 0 && c >= 0 && r < m && c < n;
        };

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0});

        vector<vector<int>> ans(m, vector<int>(n, INT_MAX));
        ans[0][0] = 0;
        
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int curr = it[0], r = it[1], c = it[2];

            if (r == m - 1 && c == n - 1) 
                return curr;

            for (int d = 1; d <= 4; ++d) {
                int nr = r + dir[d][0];
                int nc = c + dir[d][1];
                int newCost = (d == grid[r][c]) ? curr : curr + 1;

                if (isValid(nr, nc) && ans[nr][nc] > newCost) {
                    ans[nr][nc] = newCost;
                    pq.push({newCost, nr, nc});
                }
            }
        }

        return -1;
    }
};
