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
public:

    /*
       TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root or root==p or root==q){
            return root;
        }
        TreeNode* leftNode=lowestCommonAncestor(root->left,p,q);
        TreeNode* rightNode=lowestCommonAncestor(root->right,p,q);
        if(!leftNode){
            return rightNode;
        }
        else if(!rightNode){
            return leftNode;
        }else{
            return root;
        }
    }
    */

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if(root->val>p->val and root->val>q->val){
            return lowestCommonAncestor(root->left,p,q);
        }
        else if(root->val<p->val and root->val<q->val){
            return lowestCommonAncestor(root->right,p,q);
        }
        else{
            return root;
        }
    }
};