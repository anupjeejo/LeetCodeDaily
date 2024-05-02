class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> st;
        int maxElement = INT_MIN;
        int n = nums.size();

        for(int i=0; i<n; i++)
        {
            if(nums[i]<0)
                st.insert(nums[i]);
        }

        for(int i=0; i<n; i++)
        {
            if(nums[i]<0)
                continue;
            if(maxElement < nums[i] 
                && st.find((nums[i] * -1)) != st.end())
                maxElement = nums[i];
        }

        if(maxElement == INT_MIN)
            return -1;

        return maxElement;
    }
};