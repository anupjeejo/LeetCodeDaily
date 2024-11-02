class Solution {
public:
    bool isCircularSentence(string sentence) {
        char lastChar = ' ';
        int n = sentence.size();
        int idx=0;

        char firstChar = sentence[0];
        while(sentence[idx] != ' ' && idx<n)
        {
            lastChar = sentence[idx];
            idx++;
        }

        if(firstChar != lastChar && idx>=n)
            return false;

        idx++;
        while(idx<n)
        {
            if(lastChar != sentence[idx])
                return false;
        
            while(sentence[idx] != ' ' && idx<n)
            {
                lastChar = sentence[idx];                    
                idx++;
            }

            idx++;
        }

        if(firstChar != lastChar)
            return false;

        return true;
    }
};