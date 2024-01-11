    int findDiff(TreeNode *root, int maxV, int minV){
        if(!root) return abs(maxV-minV);

        maxV = max(maxV, root->val);
        minV = min(minV, root->val);

        return max(findDiff(root->left, maxV, minV), findDiff(root->right, maxV, minV));
    }

    int maxAncestorDiff(TreeNode* root){
        return findDiff(root, root->val, root->val);
    }