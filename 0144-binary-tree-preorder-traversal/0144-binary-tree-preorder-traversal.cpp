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
    
    void getans(TreeNode* root,vector<int>&res){
        if(root==NULL) return;
        res.push_back(root->val);
        getans(root->left,res);
        getans(root->right,res);
    }
   
    vector<int> preorderTraversal(TreeNode* root) {
       vector<int>res;
       getans(root,res);
       return res;
    }
};