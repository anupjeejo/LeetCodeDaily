class Solution {
public:
    int xAxisWindow = 3;
    int yAxisWindow = 3;

    int getGridLocalMax(int x, int y, vector<vector<int>>& grid)
    {
        int limitY = y + yAxisWindow - 1;
        int limitX = x + xAxisWindow - 1;
        int localMax = INT_MIN;

        for(int i=x; i<=limitX; i++)
        {
            for(int j=y; j<=limitY; j++)
            {
                localMax = max(localMax, grid[i][j]);
            }
        }

        return localMax;
    }

    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> result(n-2, vector<int> (n-2, 0));
        int yCtr = -1;

        for(int i=0; i<n; i++)
        {
            yCtr++;
            int xCtr = -1;
            for(int j=0; j<n; j++)
            {
                if((i + yAxisWindow - 1) < n
                    && (j + xAxisWindow - 1) < n)
                {
                    int localMax = getGridLocalMax(i, j, grid);
                    xCtr++;
                    result[yCtr][xCtr] = localMax;
                }
            }
        }

        return result;
    }
};