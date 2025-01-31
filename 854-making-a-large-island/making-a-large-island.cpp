class DSU {
    vector<int> parent, size;
public:
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y) {
        int xr = find(x), yr = find(y);
        if (xr == yr) return;
        if (size[xr] > size[yr]) swap(xr, yr);
        parent[xr] = yr;
        size[yr] += size[xr];
    }

    int getSize(int x) {
        return size[find(x)];
    }
};


class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU dsu(n * n);
        
        // Connect adjacent 1s
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    if (j + 1 < n && grid[i][j + 1] == 1)
                        dsu.Union(i * n + j, i * n + j + 1);
                    if (i + 1 < n && grid[i + 1][j] == 1)
                        dsu.Union(i * n + j, (i + 1) * n + j);
                    if (j - 1 >= 0 && grid[i][j - 1] == 1)
                        dsu.Union(i * n + j, i * n + j - 1);
                    if (i - 1 >= 0 && grid[i - 1][j] == 1)
                        dsu.Union(i * n + j, (i - 1) * n + j);
                }
            }
        }

        int mx = 0;
        unordered_map<int, int> islandSize;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int root = dsu.find(i * n + j);
                    islandSize[root] = dsu.getSize(root);
                }
            }
        }

        // now dfs from all 0s
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> s;
                    int curr = 1; // The flipped 0 itself counts
                    
                    // insert parent of grid with value 1
                    if (j + 1 < n && grid[i][j + 1] == 1)
                        s.insert(dsu.find(i * n + j + 1));
                    if (j - 1 >= 0 && grid[i][j - 1] == 1)
                        s.insert(dsu.find(i * n + j - 1));
                    if (i + 1 < n && grid[i + 1][j] == 1)
                        s.insert(dsu.find(i * n + j + n));
                    if (i - 1 >= 0 && grid[i - 1][j] == 1)
                        s.insert(dsu.find(i * n + j - n));

                    for (auto it : s)
                        curr += islandSize[it];

                    mx = max(mx, curr);
                }
            }
        }

        if (mx == 0) {
            for (auto& p : islandSize)
                mx = max(mx, p.second);
        }

        return mx;
    }
};
