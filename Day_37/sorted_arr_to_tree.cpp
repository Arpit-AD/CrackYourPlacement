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
    TreeNode* makeTree(vector<int>& nums, int si, int ei){
        if(si > ei)
            return NULL;
        
        int mid = (si + ei)/2;
        
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = makeTree(nums,si,mid-1);
        root->right = makeTree(nums,mid+1,ei);
        
        return root;
        
        
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        TreeNode* root = makeTree(nums,0,nums.size()-1);
        
        return root;
        
    }
};