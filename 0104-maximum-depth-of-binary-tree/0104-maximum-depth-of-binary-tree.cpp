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
    
    int maxdepth(TreeNode* root){
        if(!root) return 0;
        int heightofleftsubtree=maxdepth(root->left);
        int heightofrightsubtree=maxdepth(root->right);
        return max(heightofleftsubtree,heightofrightsubtree)+1;
    }
    
    int maxDepth(TreeNode* root) {
        return maxdepth(root);
    }
};