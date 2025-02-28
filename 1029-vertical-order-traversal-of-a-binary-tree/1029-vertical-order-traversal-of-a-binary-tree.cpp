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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*,pair<int,int>>>q;
        map<int,map<int,multiset<int>>>mp;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            TreeNode* node=p.first;
            int verticle=p.second.first,level=p.second.second;
            mp[verticle][level].insert(node->val);
            if(node->left) q.push({node->left,{verticle-1,level+1}});
            if(node->right) q.push({node->right,{verticle+1,level+1}});
        }
        vector<vector<int>>ans;
        for(auto i:mp){
            vector<int>col;
            for(auto j:i.second){
                for(auto k:j.second){
                    col.push_back(k);
                }
            }
            ans.push_back(col);
        }
        return ans;
    }
};