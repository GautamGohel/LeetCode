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
/*
  int height( TreeNode*node){
       if(node==NULL){
           return 0;
       }
       int left_height=height(node->left);
       int right_height=height(node->right);
       return max(left_height,right_height)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int a=diameterOfBinaryTree(root->left);
        int b=diameterOfBinaryTree(root->right);
        int c=height(root->left)+height(root->right)+1;
        int ans=max(a,max(b,c))-1;
        return ans;
}*/

    int solve(TreeNode* root,int &maxi){
        if(!root) return 0;
        int l=solve(root->left,maxi);
        int r=solve(root->right,maxi);
        maxi=max(l+r,maxi);
        return max(l,r)+1;
    }   
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi=0;
        solve(root,maxi);
        return maxi;
    }
};