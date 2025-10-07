class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int dp[n][n], cnt[n][n];
        const int MOD = 1e9 + 7;

        // initialize dp and cnt
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dp[i][j] = -1;
                cnt[i][j] = 0;
            }
        }

        // grid setup
        int grid[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='S' || board[i][j]=='E') grid[i][j] = 0;
                else if(board[i][j]=='X') grid[i][j] = -1;
                else grid[i][j] = board[i][j]-'0';
            }
        }

        // start point (bottom-right)
        dp[n-1][n-1] = 0;
        cnt[n-1][n-1] = 1;

        // bottom-up DP from end to start
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(grid[i][j]==-1) continue; // blocked cell

                int best = -1;

                // possible moves: down, right, diagonal
                if(i+1<n && dp[i+1][j]!=-1) best = max(best, dp[i+1][j]);
                if(j+1<n && dp[i][j+1]!=-1) best = max(best, dp[i][j+1]);
                if(i+1<n && j+1<n && dp[i+1][j+1]!=-1) best = max(best, dp[i+1][j+1]);

                if(best == -1) continue; // no path

                dp[i][j] = best + grid[i][j];

                // count paths (modulo to prevent overflow)
                long long total = 0;
                if(i+1<n && dp[i+1][j]==best) total += cnt[i+1][j];
                if(j+1<n && dp[i][j+1]==best) total += cnt[i][j+1];
                if(i+1<n && j+1<n && dp[i+1][j+1]==best) total += cnt[i+1][j+1];
                cnt[i][j] = total % MOD;
            }
        }

        // if unreachable
        if(dp[0][0] == -1) return {0,0};

        return {dp[0][0], cnt[0][0]};
    }
};