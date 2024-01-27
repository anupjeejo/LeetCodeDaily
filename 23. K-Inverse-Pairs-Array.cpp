class Solution {
public:

    int MOD = 1e9+7;

    int helper(int n, int k)
    {
        if(n == 0)
        {
            if(k == 0)
                return 1;
            return 0;
        }

        if(k<0)
            return 0;

        int ans = 0;
        for(int i=0; i<n; i++)
            ans = (ans + helper(n-1, k-i))%MOD;

        return ans%MOD;
    }
    
    int helperMem(int n, int k, vector<vector<int>> &dp)
    {
        if(n == 0)
        {
            if(k == 0)
                return 1;
            return 0;
        }

        if(k<0)
            return 0;

        if(dp[n][k] != -1)
            return dp[n][k];
            
        int ans = 0;
        for(int i=0; i<n; i++)
            ans = (ans + helperMem(n-1, k-i, dp))%MOD;

        return dp[n][k] = ans%MOD;
    }

    int helperOptimized(int n, int k)
    {
        vector<int> prev(k+1, 0);
        prev[0] = 1;

        for(int i = 1; i<=n; i++)
        {
            vector<int> curr(k+1, 0);
            int total = 0;

            for(int j=0; j<=k; j++)
            {
                if(j == 0)
                {
                    curr[j] = prev[j] = 1;
                    continue;
                }
                curr[j] = (prev[j] + curr[j-1])%MOD;
                if(j>=i)
                    curr[j] = (curr[j] - prev[j-i] + MOD)%MOD;
            }
            prev = curr;    
        }

        return prev[k]%MOD;
    }

    int kInversePairs(int n, int k) {
        if(k==0)
            return 1;
        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        //return helper(n, k);
        //return helperMem(n, k, dp);
        return helperOptimized(n, k);
    }
};