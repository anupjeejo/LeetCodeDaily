class Solution {

private:
    bool isPalindrom(string word)
    {
        int n = word.size();
        int lptr = 0;
        int rptr = n-1;

        while(lptr < rptr)
        {
            if(word[lptr++] != word[rptr--])
                return false;
        }

        return true;
    }

public:
    string firstPalindrome(vector<string>& words) {
        string result = "";

        for(auto word : words)
        {
            if(isPalindrom(word))
            {
                result = word;
                break;
            }
        }

        return result;
    }
};