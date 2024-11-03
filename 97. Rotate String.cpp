class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size())
            return false;
        
        int n = s.size();
        int ctr = 0;

        while(ctr < n)
        {
            if(s == goal)
                return true;
            char ch = s[0];
            s.erase(0,1);
            s.push_back(ch);
            ctr++;
        }

        return false;
    }
};