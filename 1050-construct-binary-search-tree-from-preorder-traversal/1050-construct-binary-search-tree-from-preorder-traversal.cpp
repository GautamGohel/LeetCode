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
    
    TreeNode* constructbst(vector<int>&preorder,int &i,int upperbound){
        if(i==preorder.size() or preorder[i]>upperbound) return NULL;
        TreeNode* node=new TreeNode(preorder[i++]);
        node->left=constructbst(preorder,i,node->val);
        node->right=constructbst(preorder,i,upperbound);
        return node;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
         int i=0;
        return constructbst(preorder,i,INT_MAX);
    }
};