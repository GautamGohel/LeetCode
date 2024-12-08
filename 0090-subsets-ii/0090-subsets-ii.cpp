class Solution {
public:

    void getallsubsets(int i,int n,vector<int>nums,vector<int>&arr,vector<vector<int>>&ds){
          ds.push_back(arr);
       for(int ind=i;ind<n;ind++){
          if(ind>i and nums[ind]==nums[ind-1]) continue;
          arr.push_back(nums[ind]);
          getallsubsets(ind+1,n,nums,arr,ds);
          arr.pop_back();
       }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>arr;
        vector<vector<int>>ds;
        getallsubsets(0,n,nums,arr,ds);
        return ds;
    }
};