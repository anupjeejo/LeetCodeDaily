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

    //BFS
    int rangeSumBST(TreeNode* root, int low, int high){
        int sum = 0;
        queue<TreeNode*> bfsQueue;

        bfsQueue.push(root);

        while(!bfsQueue.empty())
        {
            TreeNode* node = bfsQueue.front();
            bfsQueue.pop();

            if(node->val >= low && node->val <= high)
                sum += node->val;
            if(node->left != NULL)
                bfsQueue.push(node->left);
            if(node->right != NULL)
                bfsQueue.push(node->right);
        }

        return sum;
    }

    //DFS
    // int rangeSumBST(TreeNode* root, int low, int high){
    //     if(root == NULL) 
    //         return 0;

    //     if(root->val <= high && root->val >= low)
    //     {
    //         return root->val + 
    //                rangeSumBST(root->left, low, high) +
    //                rangeSumBST(root->right, low, high);
    //     }

    //     return rangeSumBST(root->left, low, high) +
    //            rangeSumBST(root->right, low, high);
    // }
};