class Solution {
public:
    int n, m;
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool isvalid(int i, int j) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }

    bool backtrack(int i, int j, int index, string& word, vector<vector<char>>& board) {
        if (index == word.size()) 
        return true;

        if (!isvalid(i, j) || board[i][j] != word[index]) return false;

        char temp = board[i][j];
        board[i][j] = '#';

        for (auto& d : dirs) {
            int ni = i + d[0], nj = j + d[1];
            if (backtrack(ni, nj, index + 1, word, board))
                return true;
        }

        board[i][j] = temp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (backtrack(i, j, 0, word, board))
                    return true;
            }
        }
        return false;
    }
};
