class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        
        for(int i=0; i<s.size(); i++) 
            mp[s[i]]++;
        
        vector<pair<int, char>> ip;
        
        for(auto it : mp) 
            ip.push_back({it.second, it.first});
        
        sort(ip.begin(), ip.end(), greater<pair<int, char>>());
        
        int j=0;
        for(auto it : ip)
            for(int i=0; i<it.first; i++)   
                s[j++] = it.second;
        
        return s;
    }
};