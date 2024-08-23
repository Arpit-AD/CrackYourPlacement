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
    vector<vector<int>> vecRoot;
    
public:
    void levelOrderTraversal(TreeNode* root)
    {
        queue<TreeNode*> pendingNodes;
        pendingNodes.push(root);
        pendingNodes.push(NULL);
        vector<int> x;
        
        while(!pendingNodes.empty())
        {
            TreeNode* front = pendingNodes.front();
            if(front == NULL)
            {
                vecRoot.push_back(x);
                x.clear();
                pendingNodes.pop();
                if(pendingNodes.empty()) break;
                else {
                    pendingNodes.push(NULL);
                    continue;
                }       
            }
            
            x.push_back(front->val);
            pendingNodes.pop();
            if(front->left)
                pendingNodes.push(front->left);
            if(front->right)
                pendingNodes.push(front->right); 
        }
        
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if(!root) return vecRoot;
        
        levelOrderTraversal(root);
        
        return vecRoot;
    }
};