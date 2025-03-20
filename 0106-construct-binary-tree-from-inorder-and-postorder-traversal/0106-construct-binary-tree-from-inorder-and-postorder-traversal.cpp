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

    TreeNode* buildbinarytree(vector<int>& inorder,int instart,int inend, vector<int>& postorder,int poststart,int postend,map<int,int>&hashmap){
        if(instart>inend or poststart>postend) return NULL;
        TreeNode* node=new TreeNode(postorder[postend]);
        int inroot=hashmap[node->val];
        int inleft=inroot-instart;
        node->left=buildbinarytree(inorder,instart,inroot-1,postorder,poststart,poststart+inleft-1,hashmap);
        node->right=buildbinarytree(inorder,inroot+1,inend,postorder,poststart+inleft,postend-1,hashmap);
        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int insize=inorder.size();
        int postsize=postorder.size();
        map<int,int>hashmap;
        for(int i=0;i<insize;i++){
            hashmap[inorder[i]]=i;
        }
       TreeNode* node= buildbinarytree(inorder,0,insize-1,postorder,0,postsize-1,hashmap);
       return node;
    }
};