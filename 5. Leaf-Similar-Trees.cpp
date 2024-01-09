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

    void helper(TreeNode* root, vector<int> &leafValues)
    {
        if(root == NULL)
            return;

        if(root->left == NULL && root->right == NULL)
        {
            leafValues.push_back(root->val);
            return;
        }

        helper(root->left, leafValues);
        helper(root->right, leafValues);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2)
    {
        vector<int> leafValues1;
        vector<int> leafValues2;

        helper(root1, leafValues1);
        helper(root2, leafValues2);

        return leafValues1 == leafValues2;
    }
};