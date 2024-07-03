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

    void solve(TreeNode* root,string Path,vector<string>&v){
        if(!root) return;
        Path+=to_string(root->val);
        if(!root->left and !root->right){
           v.push_back(Path);
        }
        Path+="->";
        solve(root->left,Path,v);
        solve(root->right,Path,v);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>v;
        solve(root,"",v);
        return v;
    }
};