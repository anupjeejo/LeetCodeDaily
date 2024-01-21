class Solution {
public:

    // brute
    int helper(vector<int> &nums, int n)
    {
        if(n<0)
            return 0;
        
        if(n==0)
            return nums[n];

        //pick house
        int res1 = nums[n] + helper(nums, n-2);
        
        //not pick house
        int res2 = helper(nums, n-1);

        return max(res1, res2);
    }

    // good
    int helperMem(vector<int> &nums, int n, vector<int> &dp)
    {
        if(n<0)
            return 0;
        
        if(n==0)
            return nums[n];

        if(dp[n] != -1)
            return dp[n];

        //pick house
        int res1 = nums[n] + helperMem(nums, n-2, dp);
        
        //not pick house
        int res2 = helperMem(nums, n-1, dp);

        return dp[n] = max(res1, res2);
    }

    // better
    int helperTab(vector<int> &nums, int n)
    {
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i=2; i<n; i++)
        {
            int res1 = dp[i-2] + nums[i];
            int res2 = dp[i-1];

            dp[i] = max(res1, res2);
        }

        return dp[n-1];
    }

    //best
    int helperOptimized(vector<int> &nums, int n)
    {
        int prev1 = nums[0];
        int prev2 = max(nums[0], nums[1]);

        for(int i=2; i<n; i++)
        {
            int res1 = prev1 + nums[i];
            int res2 = prev2;

            int temp = max(res1, res2);
            prev1 = prev2;
            prev2 = temp;
        }

        return prev2;
    }

    int rob(vector<int>& nums){
        int n = nums.size();

        if(n == 1)
            return nums[0];

        if(n == 2)
            return max(nums[0], nums[1]);

        vector<int> dp(n, -1);
        //return helper(nums, n-1);
        //return helperMem(nums, n-1, dp);
        //return helperTab(nums, n);
        return helperOptimized(nums, n);
    }

    // int loot(vector<int> &nums, int idx, int n, vector<int> &dp){
    //     if(idx>=n) return 0;

    //     if(dp[idx] != -1) return dp[idx];

    //     int r1 = loot(nums, idx+2, n, dp) + nums[idx];
    //     int r2 = loot(nums, idx+1, n, dp);

    //     return dp[idx] = max(r1, r2); 
    // }

    // int rob(vector<int>& nums){
    //     int n = nums.size();
    //     vector<int> dp(n, -1);
    //     return loot(nums, 0, n, dp);
    // }

    // int rob(vector<int>& nums){
    //     int n = nums.size(), pre = 0, cur = 0;
        
    //     for (int i = 0; i < n; i++) {
    //         int temp = max(pre + nums[i], cur);
    //         pre = cur;
    //         cur = temp;
    //     }
        
    //     return cur;
    // }
};