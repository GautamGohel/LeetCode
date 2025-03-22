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
    TreeNode* first;
    TreeNode* second;
    TreeNode* last;
    TreeNode* prev;
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
          if(root->val<prev->val){
             if(first==NULL){
                first=prev;
                second=root;
             }
             else last=root;
          }
          prev=root;
        inorder(root->right);
    }


public:
    void recoverTree(TreeNode* root) {
        first=second=last=NULL;
        prev=new TreeNode(INT_MIN);
        inorder(root);
        if(first and last){
            swap(first->val,last->val);
        }else{
            swap(first->val,second->val);
        }
    }
};