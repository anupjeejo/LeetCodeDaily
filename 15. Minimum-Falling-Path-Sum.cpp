class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& matrix) {
        for (auto i = 1; i < matrix.size(); i++) {
            for (auto j = 0; j < matrix[i].size(); j++) {
                if (j == 0)
                    matrix[i][j] += min(matrix[i - 1][j], matrix[i - 1][j + 1]);
                else if (j == matrix[i].size() - 1)
                    matrix[i][j] += min(matrix[i - 1][j], matrix[i - 1][j - 1]);
                else
                    matrix[i][j] += min(matrix[i - 1][j - 1], min(matrix[i - 1][j], matrix[i - 1][j + 1]));
            }
        }
        
        int tmp = matrix.back()[0];
        for (auto i = 0; i < matrix.back().size(); i++) {
            if (tmp > matrix.back()[i])
                tmp = matrix.back()[i];
        }
        
        return tmp;
    }
};