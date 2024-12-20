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

    void reverser(TreeNode* left, TreeNode* right, int level)
    {
        if(left == NULL) return;

        if( (level%2) == 0)
        {
            int temp = left->val;
            left->val = right->val;
            right->val = temp;
        }

        reverser(left->left, right->right, level+1);
        reverser(left->right, right->left, level+1);
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root == NULL) return NULL;
        reverser(root->left, root->right, 0);
        return root;
    }
};