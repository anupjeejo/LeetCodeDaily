class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        unordered_set<int> numSet;
        vector<int> result;

        for(auto num : nums)
        {
            if(numSet.find(num) != numSet.end())
            {
                numSet.erase(num);
                continue;
            }
            numSet.insert(num);
        }

        for(auto num : numSet)
            result.push_back(num);

        return result;
    }
};