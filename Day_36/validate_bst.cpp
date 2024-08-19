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
    bool isValidBST(TreeNode* root, pair<long,long> pr = {LONG_MIN, LONG_MAX}) {
        if(!root) return true;
        if(root->val <= pr.first || root->val >= pr.second)
            return false;
        bool left = isValidBST(root->left, {pr.first, root->val});
        bool right = isValidBST(root->right, {root->val, pr.second});

        return left&right;
    }
};