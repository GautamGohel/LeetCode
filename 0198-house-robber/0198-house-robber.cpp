class Solution {
public:
    /*
    int solve(vector<int>&nums,int ind){
        if(ind==0) return nums[0];
        if(ind<0) return 0;
        int pick=nums[ind]+solve(nums,ind-2);
        int notpick=solve(nums,ind-1);
        return max(pick,notpick);
    }
    
    int rob(vector<int>& nums) {
       return solve(nums,nums.size()-1);
    }*/
     int solve(vector<int>&nums,int ind,vector<int>&dp){
        if(ind==0) return nums[0];
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int pick=nums[ind]+solve(nums,ind-2,dp);
        int notpick=solve(nums,ind-1,dp);
        return dp[ind]=max(pick,notpick);
    }
     int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
       return solve(nums,nums.size()-1,dp);
    }
};