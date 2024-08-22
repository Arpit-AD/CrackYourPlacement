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
    vector<int> inOrder;
public:
    void Traversal(TreeNode* root){
        if(root == NULL) return;
        
        Traversal(root->left);
        inOrder.push_back(root->val);
        Traversal(root->right);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        
        /*
        Traversal(root);
        return inOrder;
        */
        
        stack<TreeNode*> st;
        TreeNode* temp = root;
        while(true) {
            if(temp) {
                st.push(temp);
                temp = temp->left;
            } 
            else {
                if(st.empty())
                    break;
                temp = st.top();
                inOrder.push_back(temp->val);
                st.pop();
                temp = temp->right;
            }
        }
        return inOrder;        
        
    }
};