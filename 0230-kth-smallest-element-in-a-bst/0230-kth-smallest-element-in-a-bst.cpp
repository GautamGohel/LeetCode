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
    
    void Morristraversal(TreeNode* root,int k,int &mini){
        int cnt=0;
        TreeNode* curr=root;
        while(curr){
            if(!curr->left){
                cnt++;
                if(cnt==k){
                    mini=curr->val;
                }
                curr=curr->right;
            }else{
                TreeNode* prev=curr->left;
                while(prev->right and prev->right!=curr){
                   prev=prev->right;
                }
                if(prev->right==NULL){
                    prev->right=curr;
                    curr=curr->left;
                }else{
                    prev->right=NULL;
                    cnt++;
                    if(cnt==k){
                        mini=curr->val;
                    }
                    curr=curr->right;
                }
            }
        }
    }
 
    int kthSmallest(TreeNode* root, int k) {
        int mini=0;
        Morristraversal(root,k,mini);
        return mini;
    }
};