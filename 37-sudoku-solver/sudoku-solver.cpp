class Solution {
public:
    bool isValidCell(vector<vector<char>>& board, int row, int col, char d) {
        // check row
        for (int j = 0; j < 9; j++) 
            if (board[row][j] == d) return false;

        // check column
        for (int i = 0; i < 9; i++) 
            if (board[i][col] == d) return false;

        // check 3x3 sub-grid
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[startRow + i][startCol + j] == d)
                    return false;

        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char d = '1'; d <= '9'; d++) {
                        if (isValidCell(board, i, j, d)) {
                            board[i][j] = d;
                            if (solve(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
