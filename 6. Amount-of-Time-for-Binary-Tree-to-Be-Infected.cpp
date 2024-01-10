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
    int result = -1;
public:

    void treeDFS(unordered_map<int, vector<int>> &graph, 
                 TreeNode* root, 
                 unordered_map<int, int> &vis)
    {
        if(root == NULL)
            return;
        
        vis[root->val] = 0;

        if(root->left != NULL)
        {
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
            treeDFS(graph, root->left, vis);
        }

        if(root->right != NULL)
        {
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
            treeDFS(graph, root->right, vis);
        }
    }

    void graphBFS(unordered_map<int, vector<int>> &graph, 
                  int node, 
                  unordered_map<int, int> &vis)
    {
        queue<int> BfsQueue;
        BfsQueue.push(node);

        while(!BfsQueue.empty())
        {
            int levelSize = BfsQueue.size();
            
            for(int i=0; i<levelSize; i++)
            {
                int currNode = BfsQueue.front();
                BfsQueue.pop();
                vis[currNode] = 1;

                for(auto adjNode : graph[currNode])
                {
                    if(!vis[adjNode])
                        BfsQueue.push(adjNode);
                }
            }

            result++;
        }
    }

    int amountOfTime(TreeNode* root, int start) 
    {
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> vis;
        
        treeDFS(graph, root, vis);
        graphBFS(graph, start, vis);

        return result;
    }
};