class Solution {
public:

//---------------------Very bad unoptimized code---------------------------------//
//     bool closeStrings(string word1, string word2){
//         if(word1.size() != word2.size()) return false;
        
//         map<char, int> mp1, mp2;
        
//         for(int i=0; i<word1.size(); i++) mp1[word1[i]]++;
//         for(int i=0; i<word2.size(); i++) mp2[word2[i]]++;
        
//         vector<int> cnt1;
//         vector<int> cnt2;
//         vector<char> cntc1;
//         vector<char> cntc2;
        
//         for(auto it : mp1) cntc1.push_back(it.first);
//         for(auto it : mp2) cntc2.push_back(it.first);
        
//         for(int i=0; i<mp1.size(); i++) cnt1.push_back(mp1[i]);
//         for(int i=0; i<mp2.size(); i++) cnt2.push_back(mp2[i]);
        
//         sort(cnt1.begin(), cnt1.end());
//         sort(cnt2.begin(), cnt2.end());
        
//         for(auto it : cnt1) cout<<it<<" ";
//         cout<<endl;
//         for(auto it : cnt2) cout<<it<<" ";
        
//         for(int i=0; i<cnt1.size(); i++)
//             if(cnt1[i] != cnt2[i]) return false;
        
//         for(int i=0; i<cntc1.size(); i++)
//             if(cntc1[i] != cntc2[i]) return false;
        
//         return true;
//     }
    
    bool closeStrings(string word1, string word2){
        if(word1.size() != word2.size()) return false;
        
        vector<int> f1(26, 0), f2(26, 0), c1(26, 0), c2(26, 0);
        
        for(auto it : word1) f1[it - 'a']++, c1[it - 'a'] = 1;
        for(auto it : word2) f2[it - 'a']++, c2[it - 'a'] = 1;
        
        sort(f1.begin(), f1.end());
        sort(f2.begin(), f2.end());
        
        return f1==f2 && c1==c2;
    }
};