class Solution {
public:
    string reversePrefix(string word, char ch) {
        string result = word;
        int n = word.size();
        int firstOccurance = 0;

        for(int i=0; i<n; i++)
        {
            if(ch == word[i])
            {
                firstOccurance = i;
                break;
            }
        }

        int ctr = 0;
        while(ctr < firstOccurance)
        {
            swap(result[ctr], result[firstOccurance]);
            ctr++;
            firstOccurance--;
        }

        return result;
    }
};