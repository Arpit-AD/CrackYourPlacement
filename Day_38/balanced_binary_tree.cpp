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
    int height(TreeNode* root, bool &balanced){
        if(!root) return 0;
        int leftH = height(root->left, balanced) + 1;
        int rightH = height(root->right, balanced) + 1;
        if(abs(leftH - rightH) >= 2) balanced = false;

        return max(leftH, rightH);
    }
    bool isBalanced(TreeNode* root) {
        bool balanced = true;
        int h = height(root, balanced);
        return balanced;
    }
};