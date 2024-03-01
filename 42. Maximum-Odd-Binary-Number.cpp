class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        string result = "";
        int n = s.size();
        int oneCount = 0;
        int zeroCount = 0;

        for(int i=0; i<n; i++)
            s[i] == '0' ? zeroCount++ : oneCount++;

        while(oneCount>1)
        {
            result+='1';
            oneCount--;
        }

        while(zeroCount>0)
        {
            result+='0';
            zeroCount--;
        }

        result+='1';
        
        return result;
    }
};