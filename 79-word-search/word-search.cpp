class Solution {
public:
    int n,m;
    vector<int> dx = {0,0,-1,1};
    vector<int> dy = {1,-1,0,0};

    bool backtrack(int idx,int i,int j, vector<vector<char>>& board,string word){

        if(idx==word.size())
        return true;

        if(board[i][j]!=word[idx])
        return false;

        char temp = board[i][j];
        board[i][j] = '#';

        for(int k=0;k<4;k++){
            int ni = i+dx[k];
            int nj = j+dy[k];
            if((ni<n && nj<m && ni>=0 && nj>=0) &&
            backtrack(idx+1,ni,nj,board,word)){
            return true;
            }
        }
        board[i][j]=temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(board[0][0]==word[0] && word.size()==1)
        return true;
           n = board.size();
           m = board[0].size();

            if(word.size())

           for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(backtrack(0,i,j,board,word))
                return true;
            }
           }

        return false;
    }
};