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
    vector<string> vec;
public:
    void recursion(TreeNode* root, string s){
        if(!root) return;
        if(root && !root->left && !root->right){
            s += to_string(root->val);
            vec.push_back(s);
            return;
        }
        s += to_string(root->val) + "->";
        recursion(root->left, s);
        recursion(root->right, s);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string s = "";
        recursion(root, s);
        return vec;
    }
};