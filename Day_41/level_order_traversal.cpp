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
    vector<vector<int>> zigzag;
public:
    void levelOrder(TreeNode* root)
    {
        queue<TreeNode*> q;
        q.push(root);
        int lev = 0;
        while(!q.empty())
        {
            int sz = q.size();
            vector<int> x;     
            TreeNode * parent = NULL;
            for(int i = 0; i < sz; i++)
            {
                if(!q.empty()) {parent = q.front(); q.pop();}
                if(parent->left)
                    q.push(parent->left);
                if(parent->right)
                    q.push(parent->right);
                x.push_back(parent->val);
            }
            if(lev & 1)
                reverse(x.begin(),x.end());
            lev++;
            zigzag.push_back(x);
        }
           
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return {};
        levelOrder(root);
        return zigzag;
    }
};