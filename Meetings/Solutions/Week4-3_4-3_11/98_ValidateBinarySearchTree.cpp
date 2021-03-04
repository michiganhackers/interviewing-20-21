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

// Note : The inorder traversal of a BST gives a sorted list

class Solution {
public:
    
    int prev = 0;
    bool visited = false;
    
    bool isValidBST(TreeNode* root) {
        
        if(!root) {
            return true;
        }
        
        if(!isValidBST(root->left)) {
            return false;
        }
         
        if(!visited) {
            prev = root->val;
            visited = true;
        } else if(root->val > prev) {
            prev = root->val;
        } else {
            return false;
        }
        
        return isValidBST(root->right);
    }
};