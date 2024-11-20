class Solution {
public:

    void printallsubset(int i,vector<int>nums,vector<vector<int>>&ds,vector<int>ans,int n){
        if(i==n){
            ds.push_back(ans);
            return ;
        }
        ans.push_back(nums[i]);
        printallsubset(i+1,nums,ds,ans,n);
        ans.pop_back();
        printallsubset(i+1,nums,ds,ans,n);
    }
   
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        vector<vector<int>>ds;
        printallsubset(0,nums,ds,ans,n);
        return ds;
    }
};