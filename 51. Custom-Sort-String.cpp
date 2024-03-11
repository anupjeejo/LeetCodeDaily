class Solution {
public:

    void add(string &result, char ch, int count)
    {
        while(count>0){
            result += ch;
            count--;
        }
    }

    string customSortString(string order, string s) {
        unordered_map<char, int> mp;
        string result;
        int n = order.size();

        for(auto ch : s)
            mp[ch]++;

        for(int i = 0; i<n; i++)
        {
            if(mp[order[i]] > 0){
                add(result, order[i], mp[order[i]]);
                mp[order[i]] = 0;
            }
        }

        for(auto ele : mp)
        {
            if(ele.second > 0){
                add(result, ele.first, ele.second);
            }
        }

        return result;
    }
};