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

    TreeNode* buildBinaryTree(vector<int>& preorder,int preStart,int preEnd,vector<int>& inorder,int inStart,int inEnd,map<int,int>&mp){
        if(inStart>inEnd or preStart>preEnd) return NULL;
        TreeNode* root=new TreeNode(preorder[preStart]);
        int inroot=mp[root->val];
        int inleft=inroot-inStart;
        root->left=buildBinaryTree(preorder,preStart+1,preStart+inleft,inorder,inStart,inroot-1,mp);
        root->right=buildBinaryTree(preorder,preStart+inleft+1,preEnd,inorder,inroot+1,inEnd,mp);
        return root;
    }
   
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mp;
        int preSize=preorder.size();
        int inSize=inorder.size();
        for(int i=0;i<inSize;i++){
            mp[inorder[i]]=i;
        }
        TreeNode* root=buildBinaryTree(preorder,0,preSize-1,inorder,0,inSize-1,mp);
        return root;
    }
};