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

    int burntree(TreeNode* target,unordered_map<TreeNode*,TreeNode*>&parent){
        int time=0;
        queue<TreeNode*>q;
        unordered_map<TreeNode*,bool>visited;
        q.push(target);
        visited[target]=true;
        while(!q.empty()){
            int size=q.size();
            bool flag=false;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left and !visited[node->left]){
                    flag=true;
                    q.push(node->left);
                    visited[node->left]=true;
                }
                if(node->right and !visited[node->right]){
                    flag=true;
                    q.push(node->right);
                    visited[node->right]=true;
                }
                if(parent.find(node)!=parent.end() and !visited[parent[node]]){
                    flag=true;
                    q.push(parent[node]);
                    visited[parent[node]]=true;
                }
            }
            if(flag) time++;
        }
        return time;
    }

    TreeNode* markparent(TreeNode* root,int start,unordered_map<TreeNode*,TreeNode*>&parent){
        queue<TreeNode*>q;
        q.push(root);
        TreeNode* target;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->val==start) target=node;
                if(node->left){
                   q.push(node->left);
                   parent[node->left]=node;
                }
                if(node->right){
                    q.push(node->right);
                    parent[node->right]=node;
                }
            }
        }
        return target;
    }
  
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*>parent;
        TreeNode* target=markparent(root,start,parent);
        return burntree(target,parent);
    }
};