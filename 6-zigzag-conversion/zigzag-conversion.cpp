class Solution {
public:
    string convert(string s, int m) {
        int n = s.length();
        if (m == 1 || m >= n) return s;

        vector<string> grid(m, string(n, '*'));

        int k = 0, i = 0, j = 0;
        while (k < n) {
            for (i = 0; i < m && k < n; i++) {
                grid[i][j] = s[k++];
            }
            i -= 2;
            j++;
            while (i > 0 && k < n) {
                grid[i--][j++] = s[k++];
            }
        }

        string ans = "";
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                if (grid[x][y] != '*') {
                    ans += grid[x][y];
                }
            }
        }
        return ans;
    }
};