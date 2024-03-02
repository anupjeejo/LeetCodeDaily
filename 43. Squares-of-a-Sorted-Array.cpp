class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums){
        // for(int i=0; i<nums.size(); i++){
        //     nums[i] *= nums[i];
        // }
        // sort(nums.begin(),nums.end());
        // return nums;
        
//--------------OPTIMAL SOLUTION-------------------------//
        int l=0,r=nums.size()-1;
        vector<int> ans(nums.size(), 0);
        
        for(int i=nums.size()-1; i>=0; i--){
            if(abs(nums[l]) > nums[r]){
                ans[i]=nums[l]*nums[l];
                l++;
            }else{
                ans[i]=nums[r]*nums[r];
                r--;
            }
        }
        
        return ans;
    }
};