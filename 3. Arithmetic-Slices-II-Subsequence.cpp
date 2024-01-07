class Solution {
public:
int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int total_count = 0;

        vector<unordered_map<int, int>> dp(n);

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                long long diff = static_cast<long long>(nums[i]) - nums[j]; 

                if (diff > INT_MAX || diff < INT_MIN)
                    continue; 

                int diff_int = static_cast<int>(diff);

                dp[i][diff_int] += 1; 

                if (dp[j].count(diff_int)) {
                    dp[i][diff_int] += dp[j][diff_int];
                    total_count += dp[j][diff_int];
                }
            }
        }

        return total_count;
    }
    
    // int result=0;

    // void helper(vector<int>& nums, int idx, int prevDiff, int count, int n)
    // {
    //     if(idx>=n)
    //     {
    //         result++;
    //         return;
    //     }

    //     if(count == 3) result++;

    //     int currDiff = -1;
    //     if(idx <= n-1) 
    //         currDiff = abs(nums[idx] - nums[idx+1]);

    //     if(currDiff == prevDiff || prevDiff == -1)
    //         helper(nums, idx+1, currDiff, count+1, n);

    //     helper(nums, idx+2, -1, 1, n);
    // }

    // int numberOfArithmeticSlices(vector<int>& nums) {
    //     int n = nums.size();
    //     helper(nums, 0, -1, 0, n);

    //     return result;
    // }
};