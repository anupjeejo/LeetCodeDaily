class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words)
    {
        int result = 0;
        unordered_set<char> st;
        bool flag;

        for(auto ch : allowed)
            st.insert(ch);

        for(auto word : words)
        {
            flag = false;
            for(auto ch : word)
            {
                if(st.find(ch) == st.end())
                {
                    flag = true;
                    break;
                }
            }
            if(!flag) 
                result++;
        }
        
        return result;
    }
};