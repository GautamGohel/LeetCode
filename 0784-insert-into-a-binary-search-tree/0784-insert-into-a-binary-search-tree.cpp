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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* curr=root;
        TreeNode* newnode=new TreeNode(val);
        if(!root) return newnode;
        while(true){
            if(curr->val<val){
                if(!curr->right){
                    curr->right=newnode;
                    break;
                }
                curr=curr->right;
            }else{
                if(!curr->left){
                    curr->left=newnode;
                    break;
                }
                curr=curr->left;
            }
        }
        return root;
    }
};