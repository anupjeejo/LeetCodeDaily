class Solution {
public:
    
    void helper(vector<vector<int>> &ans, vector<int> subset,
                vector<int> &candidates, int target, int sum, int i){
        if(sum==target){
            ans.push_back(subset);
            return;
        }
        
        if(sum>target || i>=candidates.size() ) return;
        
        subset.push_back(candidates[i]);
        helper(ans, subset, candidates, target, sum+candidates[i], i+1);
        
        subset.pop_back();
        while(i+1<candidates.size() && candidates[i] == candidates[i+1]) i++;
        helper(ans, subset, candidates, target, sum, i+1);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> subset;
        helper(ans, subset, candidates, target, 0, 0);
        return ans;   
    }
};