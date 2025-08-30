class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            set<char> s;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                if (s.find(board[i][j]) != s.end())
                    return false;
                s.insert(board[i][j]);
            }
        }

        for (int i = 0; i < n; i++) {
            set<char> s;
            for (int j = 0; j < 9; j++) {
                if (board[j][i] == '.') continue;
                if (s.find(board[j][i]) != s.end())
                    return false;
                s.insert(board[j][i]);
            }
        }

        for (int k = 0; k < 3; k++) {
            for (int h = 0; h < 3; h++) {
                set<char> s;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        char c = board[j + 3*h][i + 3*k];
                        if (c == '.') continue;
                        if (s.find(c) != s.end())
                            return false;
                        s.insert(c);
                    }
                }
            }
        }
        return true;
    }
};
