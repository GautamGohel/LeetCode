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
    
    bool ismirror(TreeNode* root1,TreeNode* root2){
        if(!root1 or !root2) return root1==root2;
        bool left=ismirror(root1->left,root2->right);
        bool right=ismirror(root1->right,root2->left);
        return root1->val==root2->val and left and right;
    }
  
    bool isSymmetric(TreeNode* root) {
        return ismirror(root->left,root->right);
    }
};