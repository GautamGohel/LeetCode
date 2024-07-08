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
class BSTiterator{
    public:
    stack<TreeNode*>st;
    bool reverse=false;//false-next true-before
    BSTiterator(TreeNode* root,bool isReverse){
       reverse=isReverse;
       pushInStack(root);
    }
    void pushInStack(TreeNode* root){
        for(;root!=NULL;){
            st.push(root);
            if(reverse){
                root=root->right;
            }
            else{
                root=root->left;
            }
        }
    }

    int next(){
        TreeNode* node=st.top();
        st.pop();
        if(reverse){
            pushInStack(node->left);
        }else{
            pushInStack(node->right);
        }
        return node->val;
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTiterator l(root,false);
        BSTiterator r(root,true);

        int i=l.next();
        int j=r.next();
        while(i<j){
            if(i+j==k) return true;
            else if (i+j<k) i=l.next();
            else j=r.next();
        }
        return false;
    }
};