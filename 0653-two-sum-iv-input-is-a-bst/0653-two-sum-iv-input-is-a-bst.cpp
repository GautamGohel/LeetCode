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
class BSTIterator {
public:
    stack<TreeNode*>st;
    bool reverse=true;//reverse->true->before else after
    BSTIterator(TreeNode* root,bool isreversed) {
       reverse=isreversed;
       pushAll(root);
    }

    void pushAll(TreeNode*  root){
        while(root){
            if(!reverse){
                st.push(root);
                root=root->left;
            }else{
                st.push(root);
                root=root->right;
            }
        }
    }

    int next() {
       TreeNode* node=st.top();
        st.pop();
        if(!reverse) pushAll(node->right);
        else pushAll(node->left);
        return node->val;
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator l(root,false);
        BSTIterator r(root,true);
        int i=l.next();
        int j=r.next();
        while(i<j){
            if(i+j==k) return true;
            else if(i+j<k) i=l.next();
            else j=r.next();
        }
        return false;
    }
};