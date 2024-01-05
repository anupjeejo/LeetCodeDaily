class Solution {
public:

    int lenCal(vector<int>& nums, int curr, int prev, vector<vector<int>> &dp, int n){
        if(curr == n) return 0;
        
        if(dp[curr][prev+1] != -1) 
            return dp[curr][prev+1];
        
        int len = lenCal(nums, curr+1, prev, dp, n);
        
        if(prev == -1 || nums[curr] > nums[prev])
            len = max(len, 1+lenCal(nums, curr+1, curr, dp, n));
        
        return dp[curr][prev+1] = len;
    }
    
    int lengthOfLIS(vector<int>& nums){
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return lenCal(nums, 0, -1, dp, n);
    }
    
// --------------Bad Approach-------------------//    
    // int lengthOfLIS(vector<int>& nums) {
    //     int cnt=0;
        
    //     for(int i=0; i<nums.size()-1; i++)
    //         if(nums[i] < nums[i+1]) cnt++;
        
    //     return cnt+1;
    // }
};