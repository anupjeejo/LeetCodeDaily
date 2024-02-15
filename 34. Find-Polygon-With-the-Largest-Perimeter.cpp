class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        long long result = -1;
        long long prevNumSum = 0;

        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++)
        {
            if(nums[i] < prevNumSum)
                result = nums[i] + prevNumSum;
            prevNumSum += nums[i];
        }

        return result;
    }
};