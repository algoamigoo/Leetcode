class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        
        int n = matrix.size();
        int n2 = matrix[0].size();

        int l = 0, h = n - 1, row = -1;
        while (l <= h) {
            int m = (l + h) / 2;
            if (matrix[m][0] > target)
                h = m - 1;
            else if (matrix[m][0] == target)
                return true;
            else {
                row = m;
                l = m + 1;
            }
        }

        if (row == -1) return false;

        l = 0, h = n2 - 1;
        while (l <= h) {
            int m = (l + h) / 2;
            if (matrix[row][m] > target)
                h = m - 1;
            else if (matrix[row][m] == target)
                return true;
            else
                l = m + 1;
        }

        return false;
    }
};
