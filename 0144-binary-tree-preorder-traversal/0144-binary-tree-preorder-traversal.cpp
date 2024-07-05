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
/*
    void solve(TreeNode*root,vector<int>&ans){
        if(root==NULL) return;
        ans.push_back(root->val);
        solve(root->left,ans);
        solve(root->right,ans);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        solve(root,ans);
        return ans;
    }*/
    /*vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(!root) return ans;
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            TreeNode* node=st.top();
            ans.push_back(node->val);
            st.pop();
            if(node->right) st.push(node->right);
            if(node->left) st.push(node->left);
        }
        return ans;
    }*/
        //Morris Traversal
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>preorder;
        TreeNode* curr=root;
        while(curr){
            if(!curr->left){
                preorder.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode* temp=curr->left;
                while(temp->right and temp->right!=curr){
                    temp=temp->right;
                }
                if(!temp->right){
                    temp->right=curr;
                    preorder.push_back(curr->val);
                    curr=curr->left;
                }
                else{
                    temp->right=NULL;
                    curr=curr->right;
                }
            }
        }
        return preorder;
    }
};