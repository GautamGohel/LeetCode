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
    /*
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
    }*/
   /* int solve(vector<int>&nums,int ind,vector<int>&dp){
        dp[0]=nums[0];
        for(int i=1;i<=ind;i++){
           int pick=nums[i];
           if(i>1) pick+=dp[i-2];
           int notpick=dp[i-1];
           dp[i]=max(pick,notpick);
        }
        return dp[ind];
    }
     int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),0);
       return solve(nums,nums.size()-1,dp);
    }
    */
    int rob(vector<int>&nums) {
    int n=nums.size();
    int prev2=0;
    int prev=nums[0];
        int ans;
        for(int i=1;i<n;i++){
           int pick=nums[i];
           if(i>1) pick+=prev2;
           int notpick=prev;
           ans=max(pick,notpick);
           prev2=prev;
           prev=ans;
        }
        return prev;
    }
};
