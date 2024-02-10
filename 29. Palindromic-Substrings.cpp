class Solution {
private:
    unordered_map<string, int> dp;

    bool isPalindrom(string s)
    {
        int n = s.size();
        int lptr = 0;
        int rptr = n-1;
        while(lptr < rptr)
        {
            if(s[lptr++] != s[rptr--])
                return false;
        }

        return true;
    }

    int helper(string s, int currIdx, int n)
    {
        if(currIdx >= n)
            return 0;

        string temp;
        int result1 = 0;
        for(int idx=currIdx; idx<n; idx++)
        {
            temp += s[idx];
            if(dp.find(temp) != dp.end())
            {
                if(dp[temp] == 1) 
                    result1++;
                continue;
            }
            isPalindrom(temp) ? 
            result1++, dp[temp] = 1 :
            dp[temp] = 0;
        }

        int result2 = helper(s, currIdx+1, n);

        int total = result1 + result2;
        return total;
    }

public:
    int countSubstrings(string s) {
        int n = s.size();
        return helper(s, 0, n);
    }
};