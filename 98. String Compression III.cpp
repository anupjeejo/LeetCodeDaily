class Solution {
public:
    string compressedString(string word) {
        string result;
        int n = word.size();
        int idx = 0;
        char prevChar = ' ';
        int ctr = 0;

        while(idx < n)
        {
            if(prevChar != word[idx])
            {
                if(prevChar != ' ' && ctr > 0)
                {
                    result += to_string(ctr);
                    result += word[idx-1];
                }
                ctr = 1;
                prevChar = word[idx];
            }
            else
                ctr++;
            
            if(ctr >= 9)
            {
                result += to_string(ctr);
                result += word[idx];
                ctr = 0;
            }

            idx++;
        }

        if(ctr > 0)
        {
            result += to_string(ctr);
            result += word[idx-1];
        }

        return result;
    }
};