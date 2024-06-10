class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int result = 0;
        int n = heights.size();
        vector<int> expected = heights;

        sort(expected.begin(), expected.end());
        
        for(int i=0; i<n; i++)
        {
            if(heights[i] != expected[i])
                result++;
        }

        return result;
    }
};