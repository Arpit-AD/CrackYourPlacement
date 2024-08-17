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
     void recursion(TreeNode* root, int &sum, bool flag)
    {
        if(!root) return;
        if(flag && !root->left && !root->right) 
            sum += root->val;
        
        recursion(root->left,sum,true);
        recursion(root->right,sum,false);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        recursion(root,sum,false);
        return sum;   
    }
};