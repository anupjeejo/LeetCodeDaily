class Solution {
public:
    vector<int> dp; 

    int getNextIndex(vector<vector<int>>& array, int l, int currentJobEnd, int n) 
    {
        int r = n-1;    
        int result = n+1;
        int mid;

        while(l <= r) {
            mid = l + (r-l)/2;
            
            if(array[mid][0] >= currentJobEnd) 
            {
                result = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        
        return result;
    }

    int helper(vector<vector<int>> &arr, int currJob, int n)
    {
        if(currJob >= n)
            return 0;

        if(dp[currJob] != -1)
            return dp[currJob];

        int nextJob  = getNextIndex(arr, currJob+1, arr[currJob][1], n);
        int ans = arr[currJob][2] + helper(arr, nextJob, n);

        ans = max(ans, helper(arr, currJob+1, n));

        return dp[currJob] = ans;
    }

    int jobScheduling(vector<int>& startTime, 
                      vector<int>& endTime, 
                      vector<int>& profit) {
        int n = profit.size();
        dp.resize(n, -1);
        vector<vector<int>> arr(n, vector<int>(3, 0));

        for(int i=0; i<n; i++)
        {
            arr[i][0] = startTime[i];
            arr[i][1] = endTime[i];
            arr[i][2] = profit[i];
        }

        sort(arr.begin(), arr.end());
        
        return helper(arr, 0, n);
    }
};