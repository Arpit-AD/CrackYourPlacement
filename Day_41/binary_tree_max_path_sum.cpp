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
    int sumPath(TreeNode* root, int &sum)
    {
        if(!root)
            return 0;
        int left = max({0,sumPath(root->left,sum)});
        int right = max({0,sumPath(root->right,sum)});
        int rootVal = max(left,right) + root->val;
        sum = max({sum,left + right + root->val});
        return rootVal;
    }
    
    int maxPathSum(TreeNode* root) {
        int sum = -1e9;
        int total = sumPath(root,sum);
        return sum;
    }
};