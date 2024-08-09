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
    int recursion(TreeNode* root, int & res){
        if(!root) return 0;
        int leftHeight = recursion(root->left, res);
        int rightHeight = recursion(root->right, res);

        int maxHeight = 1 + max(leftHeight, rightHeight);
        res = max(leftHeight + rightHeight, res);
        return maxHeight;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        int height = recursion(root, res);

        return res;
    }
};