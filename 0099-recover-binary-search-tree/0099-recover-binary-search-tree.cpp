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
        TreeNode* mid=NULL;
        TreeNode* last=NULL;
    void recoverTree(TreeNode* root) {
        inorder(root);
        if(first and last) swap(first->val,last->val);
        else if (first && mid) {
            swap(first->val, mid->val);
        }
    }
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        if(prev and prev->val>root->val){
            if(first==NULL){
                first=prev;
                mid=root;
            }else {
                last = root;
            }
        }
        prev=root;
        inorder(root->right);
    }
};