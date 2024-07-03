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
    int widthOfBinaryTree(TreeNode* root) {
        int maxwidth=0;
        if(!root){
            return maxwidth;
        }
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            int size=q.size();
            int mini=q.front().second;
            int first,last;
            for(int i=0;i<size;i++){
               TreeNode* node=q.front().first;
               long curr=q.front().second-mini;
               q.pop();
               if(i==0) first=curr;
               if(i==size-1) last=curr;
               if(node->left) q.push({node->left,2*curr+1});
               if(node->right) q.push({node->right,2*curr+2});
            }
            maxwidth=max(maxwidth,last-first+1);
        }
      return maxwidth;
    }
};