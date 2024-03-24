class Solution {
public:
    int findDuplicate(vector<int>& nums) {
//         int ctr;
        
//         sort(nums.begin(),nums.end());
        
//         ctr = nums[0];
        
//         for(int i=1; i<nums.size(); i++){
//             if(nums[i] == ctr){
//                 break;
//             }else{
//                 ctr = nums[i];
//             }
//         }
//         return ctr;
        
        int slow = nums[0], fast = nums[0];
        
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);
        
        fast = nums[0];
        
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
};