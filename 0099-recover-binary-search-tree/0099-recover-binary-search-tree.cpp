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

        TreeNode* prev=NULL;
        TreeNode* first=NULL;
        TreeNode* last=NULL;
    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(first->val,last->val);
    }
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        if(prev and prev->val>root->val){
            if(first==NULL){
                first=prev;
                last=root;
            }else {
                last = root;
            }
        }
        prev=root;
        inorder(root->right);
    }
};