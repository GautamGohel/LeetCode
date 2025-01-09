class Solution {
public:
    
    int solve(vector<int>nums,int n,vector<int>&dp){
        if(n<0) return 0;
        if(dp[n]!=-1) return dp[n];
        int pick=nums[n]+solve(nums,n-2,dp);
        int notpick=solve(nums,n-1,dp);
        return dp[n]=max(pick,notpick);
    }
  
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return solve(nums,n-1,dp);
    }
};