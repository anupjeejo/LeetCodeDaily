class Solution {
public:

    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);
        int posIdx = 0, negIdx = 1;

        for(int i=0; i<n; i++)
        {
            if(nums[i] >= 0)
            {
                result[posIdx] = nums[i];
                posIdx+=2;
            }
            else
            {
                result[negIdx] = nums[i];
                negIdx+=2;
            }
        }

        return result;
    }

    // vector<int> rearrangeArray(vector<int>& nums) {
    //     vector<int> result;
    //     queue<int> q1, q2;
    //     int n = nums.size();

    //     for(int i=0; i<n; i++)
    //     {
    //         nums[i] >= 0 ? q1.push(nums[i]) :
    //                        q2.push(nums[i]);
    //     }
        
    //     while(!q1.empty() && !q1.empty())
    //     {
    //         int topPos = q1.front();
    //         result.push_back(topPos);
    //         q1.pop();

    //         int topNeg = q2.front();
    //         result.push_back(topNeg);
    //         q2.pop();
    //     }

    //     while(!q1.empty())
    //     {
    //         int topPos = q1.front();
    //         result.push_back(topPos);
    //         q1.pop();
    //     }

    //     while(!q2.empty())
    //     {
    //         int topNeg = q2.front();
    //         result.push_back(topNeg);
    //         q2.pop();
    //     }

    //     return result;
    // }
};