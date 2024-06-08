class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();
        int sum = 0;

        mp[0] = -1;

        for(int i=0; i<n; i++)
        {
            sum += nums[i];
            int reminder = sum % k;

            if(mp.find(reminder) == mp.end())
                mp[reminder] = i;
            else if(i - mp[reminder] >= 2)
                    return true;
        }

        return false;
    }
};