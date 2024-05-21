class Solution {
public:

    vector<vector<int>> result;

    void subSetGenerator(vector<int>& nums, vector<int> &subSet, int idx)
    {
        if(idx<0)
        {
            result.push_back(subSet);
            return;
        }

        subSet.push_back(nums[idx]);
        subSetGenerator(nums, subSet, idx-1);

        subSet.pop_back();
        subSetGenerator(nums, subSet, idx-1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subSet;
        subSetGenerator(nums, subSet, nums.size()-1);

        return result;
    }
};