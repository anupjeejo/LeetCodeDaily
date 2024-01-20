class Solution {
private:
    int MOD = 1e9+7;
public:

    // int helper(vector<int>& arr, int n)
    // {
    //    if(n<0)
    //         return INT_MAX;
        
    //     if(n==0)
    //         return arr[n];

    //     int ans1 = arr[n];
    //     int mini = arr[n];

    //     for(int i = n-1; i>=0; i--)
    //     {
    //         mini = min(mini, arr[i]);
    //         ans1 += (mini%MOD);
    //     }
        
    //     int ans2 = helper(arr, n-1);
    //     return (ans1 + (ans2%MOD))%MOD;
    // }

    // int sumSubarrayMins(vector<int>& arr) {
    //     int n = arr.size();
    //     vector<int> dp(n, -1);
    //     return helper(arr, n-1);
    // }

    int sumSubarrayMins(vector<int>& arr) {
        stack<int> s;
        int n = arr.size();
        long sum = 0;
        vector<int> dp(n); 
      
        for (int i = 0; i < n; i++) 
        {
            while (!s.empty() && arr[s.top()] >= arr[i]) 
                s.pop();
        
            if (s.size()) 
            { 
              int prev = s.top();
              dp[i] = dp[prev] + (i - prev)*arr[i];

            } 
            else
                dp[i] = (i+1)*arr[i];

            sum = (sum + dp[i]) % MOD;
        
            s.push(i);
      }
      
      return (int) sum;
    }
};