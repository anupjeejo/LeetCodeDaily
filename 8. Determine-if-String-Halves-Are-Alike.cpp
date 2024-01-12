class Solution {
public:
    unordered_set<char> vowelSet{'a', 'e', 'i', 'o', 'u',
                                'A', 'E', 'I', 'O', 'U'};

    bool isVowel(char ch)
    {
        return vowelSet.find(ch) == vowelSet.end() ? false : true;
    }
    
    bool halvesAreAlike(string s){
        int lptr=0;
        int rptr=s.size()-1; 
        int cnt1=0, cnt2=0;
        
        while(lptr<rptr){
            if(isVowel(s[lptr]))
                cnt1++;
            if(isVowel(s[rptr]))
                cnt2++;
            lptr++;
            rptr--;
        }
        
        return cnt1==cnt2;
    }
};