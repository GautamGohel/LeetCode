class Solution {
public:

    int solve(vector<int>&nums,int ind,int n,int prevind,vector<vector<int>>&dp){
        if(ind==n) return 0;
        if(dp[ind][prevind+1]!=-1) return dp[ind][prevind+1];
        int nottake=solve(nums,ind+1,n,prevind,dp);
        int take=0;
        if(prevind==-1 or nums[prevind]<nums[ind])
         take=1+solve(nums,ind+1,n,ind,dp);
        return dp[ind][prevind+1]=max(nottake,take);
    }
   
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n,-1));
        return solve(nums,0,n,-1,dp);
    }
};