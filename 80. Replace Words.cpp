class Solution {
public:
    unordered_set<string> dictionarySt;

    string findWord(string word)
    {
        string temp;
        int n = word.size();

        for(int i=0; i<n; i++)
        {
            temp += word[i];
            if(dictionarySt.find(temp) != dictionarySt.end())
                return temp; 
        }

        return word;
    }

    string replaceWords(vector<string>& dictionary, string sentence) 
    {
        string result;
        string temp;
        int n = sentence.size();

        for(auto word : dictionary)
            dictionarySt.insert(word);

        for(int i=0; i<=n; i++)
        {
            if(sentence[i] == ' ' || i == n)
            {
                string ans = findWord(temp);
                result += i == n ? ans : ans + ' ';
                temp = "";
                continue;
            }
            temp += sentence[i];
        }

        return result;
    }
};