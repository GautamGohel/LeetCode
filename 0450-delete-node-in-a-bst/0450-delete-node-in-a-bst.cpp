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

    TreeNode* helper(TreeNode* node){
        TreeNode* curr=node;
        if(node->left){
            curr=curr->left;
            while(curr->right){
                curr=curr->right;
            }
           curr->right=node->right;
           return node->left;
        }else if(!node->right){
           return node->left;
        }else{
            return curr->right;
        }
    }
 
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        TreeNode* dummy=root;
        if(root->val==key) return helper(root);
        while(dummy){
            if(dummy->val<key){
                if(dummy->right and dummy->right->val==key){
                    dummy->right=helper(dummy->right);
                }else{
                    dummy=dummy->right;
                }
            }else{
                if(dummy->left and dummy->left->val==key){
                    dummy->left=helper(dummy->left);
                }else{
                    dummy=dummy->left;
                }
            }
        }
        return root;
    }
};