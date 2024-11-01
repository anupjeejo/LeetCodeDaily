class Solution {
public:
    string makeFancyString(string s) {
        string result;
        int n = s.size();
        int ctr = 1;
        char prevChar = s[0];

        result.push_back(s[0]);

        for(int i=1; i<n; i++)
        {
            prevChar == s[i] ? ctr++ : ctr = 1;
            prevChar = s[i];

            if(ctr == 3)
            {
                ctr--;
                continue;
            }
            
            result.push_back(s[i]);
        }

        return result;
    }
};