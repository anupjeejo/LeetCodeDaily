class Solution {
public:

//-------------Optimal solution-------------------------//
int majorityElement(vector<int>& nums) {
        int count = 0;
        int ele = 0;
        int n = nums.size();

        for(int i=0; i<n; i++)
        {
            if(count == 0) ele = nums[i];
            ele == nums[i] ? count++ : count--;
        }
        
        return ele;
}

//------------------Not so optimal----------------------//  
// int majorityElement(vector<int>& nums) {    
//         unordered_map<int, int> count;
//         int max=0,idx=0;
        
//         for(int i=0; i<nums.size(); i++){
//             count[nums[i]]++;
//         }
        
//         for(auto x : count){
//             if(max<x.second){
//                 max=x.second;
//                 idx=x.first;
//             }
//         }
        
//         return idx;
// }

};