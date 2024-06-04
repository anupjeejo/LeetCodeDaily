class Solution {
public:

    int longestPalindrome(string s)
    {
        vector<int> upperCaseMap(26, 0);
        vector<int> lowerCaseMap(26, 0);
        int n = s.size();
        bool isOdd = false;
        int result = 0;

        for(int i=0; i<n; i++)
        {
            s[i] >= 'A' && s[i] <= 'Z' ?
                upperCaseMap[s[i]-'A']++:
                lowerCaseMap[s[i]-'a']++;
        }

        for(int i=0; i<26; i++)
        {
            if(upperCaseMap[i] != 0)
            {
                if(upperCaseMap[i] % 2 == 0)
                    result += upperCaseMap[i];
                else
                {
                    result += upperCaseMap[i]-1;
                    isOdd = true;
                }
            }

            if(lowerCaseMap[i] != 0)
            {
                if(lowerCaseMap[i] % 2 == 0)
                    result += lowerCaseMap[i];
                else
                {
                    result += lowerCaseMap[i]-1;
                    isOdd = true;
                }
            }
        }

        return result + (isOdd ? 1 : 0);
    }
};