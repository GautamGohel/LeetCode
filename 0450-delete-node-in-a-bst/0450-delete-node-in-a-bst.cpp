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
    int getmini(TreeNode* root){
        TreeNode* node=root;
        while(node->left){
            node=node->left;
        }
        return node->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
         if(!root) return NULL;
         if(root->val==key){
            if(!root->left and !root->right){
                delete root;
                return NULL;
            }
            if(!root->left and root->right){
                TreeNode* node=root->right;
                delete root;
                return node;
            }
            if(root->left and !root->right){
                TreeNode* node=root->left;
                delete root;
                return node;
            }
            if(root->left and root->right){
                int mini=getmini(root->right);
                root->val=mini;
                root->right=deleteNode(root->right,mini);
                return root;
            }
         }
         else if(root->val<key){
            root->right=deleteNode(root->right,key);
         }
         else{
            root->left=deleteNode(root->left,key);
         }
         return root;
    }
};