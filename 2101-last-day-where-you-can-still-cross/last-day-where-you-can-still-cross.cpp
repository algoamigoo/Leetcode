#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rows, cols;
    vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

    bool canCross(int day, vector<vector<int>>& cells) {
        vector<vector<int>> grid(rows, vector<int>(cols, 0));

        // Flood the grid for the first `day` days
        for (int i = 0; i <= day; i++) {
            grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
        }

        queue<pair<int,int>> q;
        vector<vector<bool>> vis(rows, vector<bool>(cols, false));

        // Start BFS from all possible cells in top row
        for (int c = 0; c < cols; c++) {
            if (grid[0][c] == 0) {
                q.push({0, c});
                vis[0][c] = true;
            }
        }

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if (r == rows - 1) return true; // reached bottom

            for (auto& d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols &&
                    !vis[nr][nc] && grid[nr][nc] == 0) {
                    vis[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        rows = row;
        cols = col;

        int l = 0, r = row * col - 1, ans = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (canCross(mid, cells)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans + 1; // days are 1-indexed
    }
};
