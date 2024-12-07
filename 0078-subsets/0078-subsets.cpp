class Solution {
public:
    
    void getallsubsets(int i,vector<int>arr,int n,vector<int>&ans,vector<vector<int>>&db){
        if(i>=n){
            db.push_back(ans);
            return;
        }
        ans.push_back(arr[i]);
        getallsubsets(i+1,arr,n,ans,db);
        ans.pop_back();
        getallsubsets(i+1,arr,n,ans,db);
    }
  
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ds;
        vector<int>ans;
        int n=nums.size();
        getallsubsets(0,nums,n,ans,ds);
        return ds;
    }
};