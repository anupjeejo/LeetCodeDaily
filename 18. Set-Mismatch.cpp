class Solution {
public:

    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> numCount(n+1, 0);
        vector<int> result;
        int repeatingNumber = -1;
        int currSum = 0;
        int totalSum = n*(n+1)/2;
        int missingNumber = -1;

        for(int i=0; i<n; i++)
        {
            currSum += nums[i];
            numCount[nums[i]]++;
            if(numCount[nums[i]] == 2)
                repeatingNumber = nums[i]; 
        }

        missingNumber = totalSum - (currSum-repeatingNumber);

        result.push_back(repeatingNumber);
        result.push_back(missingNumber);

        return result;
    }

    // vector<int> findErrorNums(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> numCount(n+1, 0);
    //     vector<int> result;

    //     for(int i=0; i<n; i++)
    //     {
    //         numCount[nums[i]]++;
    //     }

    //     int missingNumber = -1;
    //     int repeatingNumber = -1;
    //     for(int i=0; i<n; i++)
    //     {
    //         if(numCount[i+1] == 0)
    //             missingNumber = i+1;

    //         if(numCount[nums[i]] == 2)
    //             repeatingNumber = nums[i];

    //         if(missingNumber != -1 && 
    //            repeatingNumber != -1)
    //             break;   
    //     }

    //     result.push_back(repeatingNumber);
    //     result.push_back(missingNumber);

    //     return result;
    // }
};