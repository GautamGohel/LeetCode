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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>v;
        if(!root) return v;
        bool direction=true;//true ->left to right false->right to left
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int>row(n);
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                int index=direction?i:n-i-1;
                row[index]=node->val;
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            direction=!direction;
            v.push_back(row);
        }
        return v;
    }
};