class Solution {
public:
//     bool uniqueOccurrences(vector<int>& arr) {
//         map<int, int> m;
        
//         for(int i=0; i<arr.size(); i++) m[arr[i]]++;
        
//         vector<int> ip;
        
//         for(auto it : m) ip.push_back(it.second);
        
//         sort(ip.begin(), ip.end());
        
//         for(int i=0; i<ip.size()-1; i++)
//             if(ip[i] == ip[i+1]) return false;
        
//         return true;
//     }
    
    bool uniqueOccurrences(vector<int>& arr){
        unordered_map<int, int> m;
        
        for(int i=0; i<arr.size(); i++) m[arr[i]]++;
        
        unordered_set<int> s;
        
        for(auto it : m){
            if(s.count(it.second)) 
                return false;
            else
                s.insert(it.second);
        }
        
        return true;
    }
};