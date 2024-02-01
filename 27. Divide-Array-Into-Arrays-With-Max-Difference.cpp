class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> result;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i+=3)
        {
            if(nums[i+2] - nums[i] <= k)
            {
                vector<int> temp;
                
                for(int j=i; j<=i+2; j++)
                    temp.push_back(nums[j]);
                
                result.push_back(temp);
            }
        }

        if(result.size()*3 != n)
            return {};

        return result;
    }
};