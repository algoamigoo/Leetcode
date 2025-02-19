class Solution {
public:
    int n, m, count = 0, ways = 0;
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool isvalid(int i, int j) { 
        return i >= 0 && j >= 0 && i < n && j < m; 
    }

    void backtrack(int i, int j, int k, vector<vector<int>>& grid) {
        if (!isvalid(i, j) || grid[i][j] == -1)
            return;

        if (grid[i][j] == 2) {
            if (k == count)
                ways++;
            return;
        }

        int temp = grid[i][j];
        grid[i][j] = -1;

        for (auto& d : dirs) {
            int ni = i + d[0], nj = j + d[1];
            backtrack(ni, nj, k + 1, grid);
        }

        grid[i][j] = temp;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        count = 0;
        ways = 0;

        int stix = 0, stiy = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0)  
                    count++; 
                if (grid[i][j] == 1) {
                    stix = i;
                    stiy = j;
                }
            }
        }
        count++;
        backtrack(stix, stiy, 0, grid);
        return ways;
    }
};