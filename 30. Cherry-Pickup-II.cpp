class Solution {
public:
    int x, y;
    vector<int> deltaRow = {1, 1, 1};
    vector<int> deltaCol = {-1, 0, 1};

    int helper(int currX, int currY1, int currY2, vector<vector<int>>& grid)
    {
        if(currX >= x 
           || currX < 0
           || min(currY1, currY2) < 0
           || max(currY1, currY2) >= y
           || currY1 == currY2)
           return INT_MIN;

        if(currX == x-1)
            return grid[currX][currY1] + grid[currX][currY2];
        
        int ans = 0;
        for(int idx1=0; idx1<deltaRow.size(); idx1++)
        {
            for(int idx2=0; idx2<deltaRow.size(); idx2++)
            {
                int newX = currX + deltaRow[idx1];
                int newY1 = currY1 + deltaCol[idx1];
                int newY2 = currY2 + deltaCol[idx2];

                ans = max(ans, helper(newX, newY1, newY2, grid));
            }
        }

        ans += grid[currX][currY1] + grid[currX][currY2]; 
        return ans;
    }

    int helperMem(int currX, 
                  int currY1, 
                  int currY2, 
                  vector<vector<int>>& grid, 
                  vector<vector<vector<int>>> &dp)
    {
        if(currX >= x 
            || currX < 0
            || min(currY1, currY2) < 0
            || max(currY1, currY2) >= y
            || currY1 == currY2)
            return INT_MIN;

        if(dp[currX][currY1][currY2] != -1)
            return dp[currX][currY1][currY2];

        if(currX == x-1)
            return grid[currX][currY1] + grid[currX][currY2];
        
        int ans = 0;
        for(int idx1=0; idx1<deltaRow.size(); idx1++)
        {
            for(int idx2=0; idx2<deltaRow.size(); idx2++)
            {
                int newX = currX + deltaRow[idx1];
                int newY1 = currY1 + deltaCol[idx1];
                int newY2 = currY2 + deltaCol[idx2];

                ans = max(ans, helperMem(newX, newY1, newY2, grid, dp));
            }
        }

        ans += grid[currX][currY1] + grid[currX][currY2];

        return dp[currX][currY1][currY2] = ans;
    }

    int cherryPickup(vector<vector<int>>& grid) 
    {
        x = grid.size();
        y = grid[0].size();
        vector<vector<vector<int>>> dp(x, 
                                        vector<vector<int>> (y, 
                                        vector<int> (y, -1)));
        
        // return helper(0, 0, y-1, grid);
        return helperMem(0, 0, y-1, grid, dp);
    }
};