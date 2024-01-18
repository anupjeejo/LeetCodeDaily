class Solution {
public:

    // recursive
    int helper(int steps)
    {
        if(steps<0)
            return 0;
        
        if(steps == 0)
            return 1;
        
        return helper(steps-1) +
               helper(steps-2);
    }

    //Memoization
    int helperMem(int steps, vector<int> &dp)
    {
        if(steps<0)
            return 0;

        if(steps == 0)
            return 1;

        if(dp[steps] != -1)
            return dp[steps];
        
        return dp[steps] = helper(steps-1) +
                           helper(steps-2);
    }

    //Tabulation
    int helperTab(int steps)
    {
        vector<int> dp(steps+1, 0);

        dp[0] = 1;

        for(int i=1; i<=steps; i++)
        {
            int ans1=0;
            if(i>=2) ans1 = dp[i-2];
            
            int ans2 = dp[i-1];

            dp[i] = ans1+ans2;
        }
        
        return dp[steps];
    }

    //Optimization
    int helperOptimal(int steps)
    {
        int prev1=0;
        int prev2=1;

        for(int i=1; i<=steps; i++)
        {
            int ans = prev1 + prev2;
            prev1 = prev2;
            prev2 = ans;
        }
        
        return prev2;
    }

    int climbStairs(int n) {
        //vector<int> dp(n+1 , -1);
        //return helper(n);
        //return helperMem(n, dp);
        //return helperTab(n);
        return helperOptimal(n);
    }
};