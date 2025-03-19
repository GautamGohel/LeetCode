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
 
    int getleftheight(TreeNode* root){
        if(!root) return 0;
        return 1+getleftheight(root->left);
    }
 
    int getrightheight(TreeNode* root){
        if(!root) return 0;
        return 1+getrightheight(root->right);
    }

    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int lh=getleftheight(root);
        int rh=getrightheight(root);
        if(lh==rh){
            return (1<<lh)-1;
        }else{
            return countNodes(root->left)+countNodes(root->right)+1;
        }
    }
};