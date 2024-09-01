class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n){
//-------good and optimal but not well strucutred-------------//
//         int size=original.size(),ctr=0;
//         vector<vector<int>> ans();
//         vector<int> subset;
        
//         if(size == (m*n)){
//             for(int i=0; i<m; i++){
//                 for(int j=0; j<n; j++){
//                     subset.push_back(original[ctr]);
//                     ctr++;
//                 }
//             ans.push_back(subset);
//             subset.clear();
//             }
//         }
//         return ans;
        
//---------optimal and well structured-----------------------//
        
        int size=original.size();
        vector<vector<int>> ans(m, vector<int>(n));
        
        if(size != (m*n)){
            return {};
        }
        
        for(int i=0; i<m; i++){
                for(int j=0; j<n; j++){
                    ans[i][j] = original[n*i+j];  
                }
        }
        
        return ans;
    }
};