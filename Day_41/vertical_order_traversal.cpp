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
    map<int, vector<pair<int,int>>> mp;
public:
    void traverse(TreeNode* root, int h, int v){
        if(!root) return;
        mp[h].push_back({v, root->val});
        traverse(root->left, h-1, v+1);
        traverse(root->right, h+1, v+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        traverse(root, 0, 0);
        vector<vector<int>> res;
        for(auto it: mp){
            vector<int> vc;
            sort(it.second.begin(), it.second.end());
            for(auto z: it.second) vc.push_back(z.second);
            res.push_back(vc);
        }

        return res;
    }
};