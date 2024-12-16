class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) 
    {
        priority_queue<
                        pair<int, int>, 
                        vector<pair<int, int>>, 
                        greater<pair<int, int>>
                    > pq;
        int n = nums.size();
        
        for(int idx=0; idx<n; idx++)
            pq.push({nums[idx], idx});

        while(k>0)
        {
            pair<int, int> topElement = pq.top();
            int num = topElement.first;
            int index = topElement.second;

            pq.pop();
            num *= multiplier;
            pq.push({num, index});
            k--;
        }

        while(!pq.empty())
        {
            pair<int, int> topElement = pq.top();
            int num = topElement.first;
            int index = topElement.second;

            nums[index] = num;
            pq.pop();
        }

        return nums;
    }
};