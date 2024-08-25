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
    long long ans = 0, sum; 
    unordered_map<long long, long long> mp;
public:
    void dfs(TreeNode * root, int target = 0){
        if(!root) return;
        target += root->val;
        ans += mp[target - sum];
        mp[target]++;
        dfs(root->left, target);
        dfs(root->right, target);
        mp[target]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        sum = targetSum;
        mp[0] = 1;
        if(!root) return ans;
        dfs(root);
        return ans;
    }
};