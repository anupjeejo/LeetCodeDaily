class Solution {
public:
    int missingNumber(vector<int>& nums){
//          my approch
//         int index;
//         sort(nums.begin(), nums.end());
        
//         for(int i=0; i<nums.size(); i++){
//             if(nums[i] != i){
//                 index = i;
//                 break;
//             }
//         }
        
//         return index;
        
// optimized approach

        int n=nums.size();
        int sum1=0,sum2=(n*(n+1))/2;
        
        for(int i=0; i<nums.size(); i++ ){
            sum1 += nums[i];
        }
        
        return sum2-sum1;
    }
};