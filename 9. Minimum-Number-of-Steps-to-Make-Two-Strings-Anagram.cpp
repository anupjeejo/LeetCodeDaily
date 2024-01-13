class Solution {
public:
    int minSteps(string s, string t) {
        int n = s.size();
        vector<int> charCountS(26, 0);
        vector<int> charCountT(26, 0);
        int result=0;

        for(int i=0; i<n; i++)
        {
            charCountS[s[i]-'a']++;
            charCountT[t[i]-'a']++;
        }

        for(int i=0; i<n; i++)
        {
            if(charCountT[s[i]-'a'] > 0)
            {
                charCountS[s[i]-'a']--;
                charCountT[s[i]-'a']--;
            }
            else
            {
                result += charCountS[s[i]-'a'] <= 0 ? 0 : charCountS[s[i]-'a'];
                charCountS[s[i]-'a'] -= charCountS[s[i]-'a'];
            }
        }

        return result;
    }
};