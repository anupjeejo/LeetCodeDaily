class Solution {
public:
    int appendCharacters(string s, string t) {
        int n = s.size();
        int m = t.size();
        int ctr1 = 0, ctr2 = 0;

        while(ctr1 < n && ctr2 < m)
        {
            if(s[ctr1] == t[ctr2])
                ctr2++;
            ctr1++;
        }

        return m-ctr2;
    }
};