class Solution {
public:
    
//--------------------Brute Force--------------------------------//
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int n=nums.size(), total=1;
//         vector<int> ans(n);
        
//         for(int i=0; i<n; i++){
//             total=1;
//             for(int j=0; j<n; j++){
//                 if(j!=i) total *= nums[j];
//             }
//             ans[i] = total;
//         }
        
//         return ans;
//     }

//----------------No TLE but yet not optimal(TC=O(4n), SC=O(2n))------------------//
//     vector<int> productExceptSelf(vector<int>& nums){
//         int n=nums.size();
//         vector<int> l(n), r(n), pro(n);
        
//         for(int i=0; i<n; i++){
//             l[i]=nums[i];
//             r[i]=nums[i];
//         }
        
//         for(int i=1; i<n; i++) l[i] = l[i] * l[i-1];
//         for(int i=n-2; i>0; i--) r[i] = r[i] * r[i+1];
        
//         pro[0]=r[1];
//         pro[n-1]=l[n-2];
        
//         for(int i=1; i<n-1; i++) pro[i] = l[i-1]*r[i+1];
        
//         return pro;
//     }

//-----------------Optimal Solution----------------------------//
    vector<int> productExceptSelf(vector<int>& nums){
        int n=nums.size(), product=1;
        vector<int> pro(n);
        
        for(int i=0; i<n; i++){
            product *= nums[i];
            pro[i] = product;
        }
        
        product=1;
        
        for(int i=n-1; i>0; i--){
            pro[i] = pro[i-1] * product;
            product *= nums[i];
        }
        
        pro[0]=product;
        
        return pro;
    }
};