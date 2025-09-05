class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {

        // basically, Traverse from 0,0 to n-1,m-1
        // with minimising the maximum number encountered

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        pq.push({grid[0][0], {0, 0}});
        dist[0][0] = grid[0][0];
        while (!pq.empty()) {
            auto it = pq.top();
            int curr = it.first;
            int i = it.second.first;
            int j = it.second.second;
            if (i == n - 1 && j == m - 1)
                return curr;
            pq.pop();
            int nx, ny;
            for (int d = 0; d < 4; d++) {
                nx = i + dx[d];
                ny = j + dy[d];
                if (nx >= 0 && ny >= 0 && nx < n && ny < m &&
                    dist[nx][ny] == INT_MAX) {
                    if (dist[nx][ny] > dist[i][j] + grid[nx][ny]) {
                        dist[nx][ny] = dist[i][j] + grid[nx][ny];
                        pq.push({dist[nx][ny], {nx, ny}});
                    }
                }
            }
        }
        return dist[n - 1][m - 1];
    }
};