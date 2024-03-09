class Solution {
public:
    // int getCommon(vector<int>& nums1, vector<int>& nums2) {
    //     int result = -1;
    //     int n = nums1.size();
    //     int m = nums2.size();
    //     int ctr1 = 0;
    //     int ctr2 = 0;

    //     while(ctr1<n && ctr2<m)
    //     {
    //         if(nums1[ctr1] == nums2[ctr2])
    //         {
    //             result = nums1[ctr1];
    //             break;
    //         }
    //         else if(nums1[ctr1] > nums2[ctr2])
    //             ctr2++;
    //         else
    //             ctr1++;
    //     }

    //     return result;
    // }

    bool binarySearch(vector<int> &nums2, int target)
    {
        int right = nums2.size()-1;
        int left = 0;

        while(left<=right)
        {
            int mid = left + (right - left)/2;
            if(nums2[mid] == target)
                return true;
            else if(nums2[mid] > target)
                right = mid-1;
            else
                left = mid+1;
        }

        return false;
    }

    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        for(auto num : nums1)
        {
            if(binarySearch(nums2, num))
                return num;
        }

        return -1;
    }
};