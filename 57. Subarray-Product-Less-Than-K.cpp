class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int result = 0;
        int n = nums.size();
        int lptr = 0, rptr = 0;
        int product = 1;

        while(rptr < n)
        {
            product *= nums[rptr++];
            
            while(product >= k && lptr < rptr)
                product /= nums[lptr++]; 
            
            if(product < k) 
                result += (rptr - lptr);
        }

        return result;
    }
};