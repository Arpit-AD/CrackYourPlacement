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
    void recursion(TreeNode* root, int level, vector<int> & rightView){
        if(!root) return;
        if(rightView.size() < level && root){
            rightView.push_back(root->val);
        }

        recursion(root->right, level+1, rightView);
        recursion(root->left, level+1, rightView);
    }
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        int level = 1;
        vector<int> rightView;
        rightView.push_back(root->val);
        recursion(root, level, rightView);

        return rightView;    
    }
};