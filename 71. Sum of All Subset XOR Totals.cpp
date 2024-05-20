class Solution {
public:
    int subSetXORSumCalculator(vector<int>& nums, int idx, int XORSum, int n)
    {
        if(idx >= n)
            return XORSum;

        int pick = subSetXORSumCalculator(nums, idx+1, XORSum^nums[idx], n);
        int notPick = subSetXORSumCalculator(nums, idx+1, XORSum, n);

        return pick + notPick;
    }

    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        return subSetXORSumCalculator(nums, 0, 0, n);
    }
};