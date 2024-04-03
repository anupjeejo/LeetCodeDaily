class Solution {
public:
    
    
    bool helper(int i, int j, int n, int m, int idx, vector<vector<char>>& board, 
                string &word){
        
        if(idx == word.size()) return true;
        
        if(i>=n || i<0 || j>=m || j<0 || board[i][j] != word[idx]) return false;
…        }
        
        return false;
    }
};