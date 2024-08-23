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
    int prev = -1;
    void recursion(TreeNode* root, int &mini){
        if(!root) return;
        recursion(root->left, mini);

        if(prev >= 0) mini = min(mini, root->val - prev);
        prev = root->val;

        recursion(root->right, mini);
    }
    int getMinimumDifference(TreeNode* root) {
        int mini = INT_MAX;
        recursion(root, mini);
        return mini;
    }
};