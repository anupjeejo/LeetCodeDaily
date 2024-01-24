/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private:
    int result=0;

    bool check( vector<int> &numMap)
    {
        int oddCount = 0;
        int evenCount = 0;

        for(auto num : numMap)
        {
            if(num == 0)
                continue;
            num % 2 == 0 ? evenCount++ : oddCount++;
        }

        return (evenCount >= 1 && oddCount <= 1) ||
                (evenCount == 0 && oddCount == 1);
    }

    void checkPalindrom(TreeNode* root, vector<int> &numMap)
    {
        if(root == NULL)
            return;

        numMap[root->val]++;

        if(root->left == NULL && root->right == NULL)
        {
            if(check(numMap))
                result++;

            numMap[root->val]--;
            return;
        }
            
        checkPalindrom(root->left, numMap);
        checkPalindrom(root->right, numMap);

        numMap[root->val]--;
    }

public:

    int pseudoPalindromicPaths (TreeNode* root) 
    {
        if(root->left == NULL && root->right == NULL)
            return 1;

        vector<int> numMap(10, 0);
        checkPalindrom(root, numMap);

        return result;
    }
};