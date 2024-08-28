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
    int count=0;
    
    int has_camera=0;
    int needs_camera=1;
    int camera_covered=2;
    int not_needed_camera=3;
    
public:
    int minCameraCover(TreeNode* root) {
       if(status_of_node(root)==needs_camera)
           count=count+1;
        else count=count;
        return count;
    }
    
    int status_of_node(TreeNode* root){
        if(root==NULL)
        {
            return not_needed_camera;
        }
        if(root->left==NULL && root->right==NULL)
        {
            return needs_camera;
        }
        
        int left= status_of_node(root->left);
        int right= status_of_node(root->right);

        if(left==needs_camera || right==needs_camera)
        {
            count++;
            return has_camera;
        }
        if(left== has_camera || right== has_camera)
        {
            return camera_covered;
        }
        return needs_camera;
    }
};