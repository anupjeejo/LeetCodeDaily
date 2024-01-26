class Solution {
public:
    int MOD = 1e9+7;
    vector<int> deltaRow = { 0,-1, 0,+1};
    vector<int> deltaCol = {-1, 0,+1, 0};

    int dfs(int m, 
            int n, 
            int currRow, 
            int currCol, 
            int remainingMoves, 
            vector<vector<vector<int>>> &dp)
    {
        if(remainingMoves >= 0 &&
            (currRow>=m || 
            currRow<0 || 
            currCol>=n || 
            currCol<0)
        )
        {
            return 1;
        }
        
        if(remainingMoves<=0)
            return 0;

        if(dp[currRow][currCol][remainingMoves] != -1)
            return dp[currRow][currCol][remainingMoves];

        int ans = 0;
        for(int idx=0; idx<4; idx++)
        {
            int row = currRow + deltaRow[idx];
            int col = currCol + deltaCol[idx];
            ans = ((ans%MOD) + dfs(m, n, row, col, remainingMoves-1, dp))%MOD;
        }

        return dp[currRow][currCol][remainingMoves] = ans%MOD;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m,
                                        vector<vector<int>> (n, 
                                        vector<int>(maxMove+1, -1)));

        return dfs(m, n, startRow, startColumn, maxMove, dp);
    }
};