class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        int lptr = 0;
        int rptr = n-1;
        int result = 0;

        while(lptr<rptr)
        {
            if(s[lptr] == s[rptr])
            {
                while(s[lptr] == s[lptr+1] && lptr<rptr)
                    lptr++;
                while(s[rptr] == s[rptr-1] && lptr<rptr)
                    rptr--;
                lptr++;
                rptr--;
            }
            else break;
        }

        result = rptr-lptr+1;

        if(result<=0)
            return 0;

        return result;
    }
};