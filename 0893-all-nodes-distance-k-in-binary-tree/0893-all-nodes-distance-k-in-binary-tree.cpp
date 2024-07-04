/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
   
   void markParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&mp){
     queue<TreeNode*>q;
     q.push(root);
     while(!q.empty()){
        TreeNode* node=q.front();
        q.pop();
        if(node->left){
            mp[node->left]=node;
            q.push(node->left);
        }
        if(node->right){
            mp[node->right]=node;
            q.push(node->right);
        }
     }
   }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>mp;
        markParent(root,mp);
        unordered_map<TreeNode*,bool>visited;
        queue<TreeNode*>q;
        q.push(target);
        visited[target]=true;
        int dist=0;
        while(!q.empty()){
           if( dist==k) break;
           dist++;
           int size=q.size();
           for(int i=0;i<size;i++){
              TreeNode* node=q.front();
              q.pop();
              if(node->left and !visited[node->left]){
                 q.push(node->left);
                 visited[node->left]=true;
              }
              if(node->right and !visited[node->right]){
                q.push(node->right);
                visited[node->right]=true;
              }
              if(mp[node] and !visited[mp[node]]){
                q.push(mp[node]);
                visited[mp[node]]=true;
              }
           }
        }
           vector<int>ans;
           while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
           }
        return ans;
    }
};