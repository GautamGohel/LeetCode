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

    TreeNode* buildBtree(vector<int>&preorder,int prestart,int preend,vector<int>&inorder,int instart,int inend,map<int,int>&hashmap){
        if(prestart>preend or instart>inend) return NULL;
         TreeNode* node=new TreeNode(preorder[prestart]);
         int inroot=hashmap[node->val];
         int gap=inroot-instart;
         node->left=buildBtree(preorder,prestart+1,gap+prestart,inorder,instart,inroot-1,hashmap);
         node->right=buildBtree(preorder,prestart+gap+1,preend,inorder,inroot+1,inend,hashmap);
         return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>hashmap;
        int presize=preorder.size();
        int insize=inorder.size();
        for(int i=0;i<insize;i++){
            hashmap[inorder[i]]=i;
        }
        TreeNode* root=buildBtree(preorder,0,presize-1,inorder,0,insize-1,hashmap);
        return root;
    }
};