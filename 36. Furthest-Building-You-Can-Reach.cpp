class Solution {
public:

    // int helper(vector<int>& heights, int bricks, int ladders, int n, int currBuilding, int prevBuildingHeight)
    // {
    //     if(currBuilding >= n)
    //         return 0;

    //     if(heights[currBuilding] <= prevBuildingHeight)
    //         return 1 + helper(heights, bricks, ladders, n, currBuilding+1, heights[currBuilding]);

    //     if(bricks <= 0 && ladders <= 0)
    //         return 0;

    //     int currHeight = heights[currBuilding];
    //     int heightRequired = currHeight - prevBuildingHeight;
    //     int res1 = 0;
    //     if(bricks >= heightRequired)
    //     {
    //         res1 = 1 + helper(heights, bricks-heightRequired, ladders, n, currBuilding+1, heights[currBuilding]);
    //     }

    //     int res2 = 0;
    //     if(ladders >= 1)
    //     {
    //         res2 = 1 + helper(heights, bricks, ladders-1, n, currBuilding+1, heights[currBuilding]);
    //     }

    //     return max(res1, res2);
    // }

    // int helperMem(vector<int>& heights, 
    //                 int bricks, 
    //                 int ladders, 
    //                 int n, 
    //                 int currBuilding, 
    //                 int prevBuildingHeight,
    //                 vector<vector<vector<int>>> &dp)
    // {
    //     if(currBuilding >= n)
    //         return 0;

    //     if(dp[currBuilding][bricks][ladders] != -1)
    //         return dp[currBuilding][bricks][ladders];

    //     if(heights[currBuilding] <= prevBuildingHeight)
    //         return dp[currBuilding][bricks][ladders] = 1 + helperMem(heights, 
    //                                                 bricks, 
    //                                                 ladders,
    //                                                 n,
    //                                                 currBuilding+1, 
    //                                                 heights[currBuilding],
    //                                                 dp);

    //     if(bricks <= 0 && ladders <= 0)
    //         return 0;

    //     int currHeight = heights[currBuilding];
    //     int heightRequired = currHeight - prevBuildingHeight;
    //     int res1 = 0;
    //     if(bricks >= heightRequired)
    //     {
    //         res1 = 1 + helperMem(heights, 
    //                              bricks-heightRequired, 
    //                              ladders, 
    //                              n, 
    //                              currBuilding+1, 
    //                              heights[currBuilding],
    //                              dp);
    //     }

    //     int res2 = 0;
    //     if(ladders >= 1)
    //     {
    //         res2 = 1 + helperMem(heights, 
    //                              bricks, 
    //                              ladders-1, 
    //                              n, 
    //                              currBuilding+1, 
    //                              heights[currBuilding],
    //                              dp);
    //     }

    //     return dp[currBuilding][bricks][ladders] = max(res1, res2);
    // }

    // int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        // int n = heights.size();
        // vector<vector<vector<int>>> dp(n, 
        //                                vector<vector<int>> (bricks-1, 
        //                                vector<int> (ladders-1, -1)));
        // return helper(heights, bricks, ladders, n, 1, heights[0]);
        // return helperMem(heights, bricks, ladders, n, 1, heights[0], dp);
    // }

    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        int result = 0;
        priority_queue<int> pq;

        for(int i=0; i<n-1; i++)
        {
            int heightDiff = heights[i] - heights[i+1];
            
            if(heightDiff>=0)
                continue;
            
            int reqBricks = abs(heightDiff);
            bricks -= reqBricks;
            pq.push(reqBricks);

            if(bricks < 0)
            {
                if(ladders <= 0)
                    return i;

                int newBricks = pq.top();
                pq.pop();
                bricks += newBricks;
                ladders--;
            }
        }

        return n-1;
    }
};