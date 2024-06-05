class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> result;
        vector<int> charCount(26, 0);
        int n = words.size();

        for(auto word : words)
        {
            for(int i=0; i<word.size(); i++)
                charCount[word[i]-'a']++;
        }

        for(auto word : words)
        {
            vector<int> currCharCount(26, 0);;
            int wordSize = word.size();

            for(int i=0; i<wordSize; i++)
                currCharCount[word[i]-'a']++;

            for(int j=0; j<charCount.size(); j++)
                charCount[j] = min(charCount[j], currCharCount[j]);
        }

        for(int i=0; i<charCount.size(); i++)
        {
            for(int letterCount=0; letterCount<charCount[i]; letterCount++)
                result.push_back(string(1, i + 'a'));
        }

        return result;
    }
};