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
    
    TreeNode* constructBST(vector<int>& preorder,int &i,int UB){
        if(i==preorder.size() or preorder[i]>UB) return NULL;
        TreeNode* node=new TreeNode(preorder[i++]);
        node->left=constructBST(preorder,i,node->val);
        node->right=constructBST(preorder,i,UB);
        return node;
    }
  
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return constructBST(preorder,i,INT_MAX);
    }
};