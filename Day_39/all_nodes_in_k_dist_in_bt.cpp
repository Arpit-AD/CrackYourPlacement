/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    vector<vector<int>> adj;
    vector<int> ans;
public:
    int giveCount(TreeNode* root)
    {
        if(!root) return 0;
        return 1 + giveCount(root->left) + giveCount(root->right);
    }
    
    void createGraph(TreeNode* root)
    {
        if(!root) return;
        int leftVal = root->left ? root->left->val : -1;
        int rightVal = root->right ? root->right->val : -1;
        
        if(leftVal != -1) 
        {
            adj[root->val].push_back(leftVal);
            adj[leftVal].push_back(root->val);
        }
        if(rightVal != -1)
        {
            adj[root->val].push_back(rightVal);
            adj[rightVal].push_back(root->val);
        }
        createGraph(root->left);
        createGraph(root->right);
    }
    
    void print(int n)
    {
        for(int i = 0; i < n; i++)
        {
            cout << i << " : ";
            for(auto x : adj[i])
                cout << x << " ";
            cout << "\n";
        }
    }
    
    void dfs(vector<int> visited, int target, int k)
    {
        if(k == 1)
        {
            for(auto z: adj[target])
                if(visited[z] == 0)
                    ans.push_back(z);
        }
        
        visited[target] = 1;
        for(auto x: adj[target])
        {
            if(visited[x] == 0)
                dfs(visited,x,k-1);
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root) return ans;
        int n = giveCount(root);
        if(k > n) return ans;
        
        if(k == 0){
            ans.push_back(target->val);
            return ans;
        }
        
        adj.resize(n);
        createGraph(root);
        // print(n);
        vector<int> visited(n,0);
        dfs(visited,target->val,k);
        
        return ans;
    }
};