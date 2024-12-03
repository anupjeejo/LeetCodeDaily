class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string result;
        int n = s.size();
        int spacesSize = spaces.size();
        int spacesIdx = 0;

        for(int idx=0; idx<n; idx++)
        {
            if(spacesIdx < spacesSize 
                && idx == spaces[spacesIdx])
            {
                result.push_back(' ');
                spacesIdx++;
            }
            result.push_back(s[idx]);
        }

        return result;
    }
};