class Solution {
public:

    // int maximumCount(vector<int> &nums)
    // {
    //     int negCount = 0;
    //     int posCount = 0;

    //     for(auto num : nums)
    //     {
    //         if(num == 0) continue; 
            
    //         num < 0 ?
    //             negCount++ : 
    //             posCount++;
    //     }

    //     return max(negCount, posCount);
    // }

    int binarySearch(vector<int> &nums, bool isUpperBound)
    {
        int first = 0;
        int last = nums.size()-1;
        int mid;
        int idx = -1;

        while(first <= last)
        {
            mid = (first + last)/2;

            if(nums[mid] == 0)
            {
                isUpperBound ?
                    last = mid-1:
                    first = mid+1;
                continue;
            }
            if(nums[mid] < 0)
            {
                if(isUpperBound)
                {
                    idx = mid;
                    first = mid+1;
                }
                else
                    first = mid+1;
            }
            else
            {
                if(isUpperBound)
                {
                    last = mid-1;
                }
                else
                {
                    idx = mid;
                    last = mid-1;
                }
            }
        }

        return idx;
    }

    int maximumCount(vector<int> &nums) {
        int firstPosIdx = binarySearch(nums, false);
        int lastNegIdx = binarySearch(nums, true);

        if(firstPosIdx == -1 && lastNegIdx == -1)
            return 0;
        else if(firstPosIdx == -1 && lastNegIdx != -1)
            return lastNegIdx+1;
        else if(firstPosIdx != -1 && lastNegIdx == -1)
            return nums.size()-firstPosIdx;
        
        firstPosIdx = nums.size()-firstPosIdx;

        return max(firstPosIdx, lastNegIdx+1); 
    }
};