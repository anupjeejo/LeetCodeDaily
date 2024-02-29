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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        int level = -1;
        q.push(root);

        while(!q.empty())
        {
            int n = q.size();
            int prev = -1;
            level++;
            
            for(int i=0; i<n; i++)
            {
                TreeNode *top = q.front();
                int topVal = top->val;
                
                if(level%2 == 0)
                {
                    if(topVal%2 != 1 ||
                       (prev != -1 && prev>=topVal))
                        return false;
                }
                else
                {
                    if(topVal%2 != 0 ||
                       (prev != -1 && topVal >= prev))
                        return false;
                }
                if(top->left != NULL) q.push(top->left);
                if(top->right != NULL) q.push(top->right);
                prev = topVal;
                q.pop();
            }
        }

        return true;
    }
};