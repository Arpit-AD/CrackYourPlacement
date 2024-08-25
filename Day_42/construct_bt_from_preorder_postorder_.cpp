/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* maketree(vector<int>& preorder, vector<int>& postorder,
                       int& preidx, int left, int right, int size) {
        if (left > right || preidx >= size)
            return NULL;

        TreeNode* root = new TreeNode(preorder[preidx]);
        preidx++;
        if (left == right)
            return root;
        int i = 0;
        for (i = left; i <= right; i++) {
            if (preorder[preidx] == postorder[i])
                break;
        }
        if (i <= right) {
            root->left = maketree(preorder, postorder, preidx, left, i, size);
            root->right =
                maketree(preorder, postorder, preidx, i + 1, right - 1, size);
        }
        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder,
                                   vector<int>& postorder) {
        int preidx = 0;
        return maketree(preorder, postorder, preidx, 0, preorder.size() - 1,
                        preorder.size());
    }
};