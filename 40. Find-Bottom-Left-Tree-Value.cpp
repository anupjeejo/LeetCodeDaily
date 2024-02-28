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
public:
    
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        TreeNode* result;
        q.push(root);

        while(!q.empty())
        {
            result = q.front();
            q.pop();
            if(result->right != NULL)
                q.push(result->right);
            if(result->left != NULL)
                q.push(result->left);
        }

        return result->val;
    }
};