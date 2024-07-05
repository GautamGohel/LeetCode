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
 //recursive
 /*
    void solve(TreeNode* root,vector<int>&ans){
        if(root==NULL) return;
        solve(root->left,ans);
        ans.push_back(root->val);
        solve(root->right,ans);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;7y7
        solve(root,ans);
        return ans;
    }
*/

   //iterative
  /*  vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;
        stack<TreeNode*> st;
        TreeNode* node = root;

        while (node != nullptr || !st.empty()) {
            if (node) {
                st.push(node);
                node = node->left;
            } else {
                node = st.top();
                st.pop();
                ans.push_back(node->val);
                node = node->right;
            }
        }

        return ans;
    }
    */
    //Morris Traversal
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>inorder;
        TreeNode* curr=root;
        while(curr){
            if(!curr->left){
                inorder.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode* temp=curr->left;
                while(temp->right and temp->right!=curr){
                    temp=temp->right;
                }
                if(!temp->right){
                    temp->right=curr;
                    curr=curr->left;
                }
                else{
                    temp->right=NULL;
                    inorder.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        return inorder;
    }
};