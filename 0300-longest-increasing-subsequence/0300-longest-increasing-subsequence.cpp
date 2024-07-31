class Solution {
public:
   
    // int solve(int ind,vector<int>arr,int n,int prevind,vector<vector<int>>&dp){
    //     if(ind==n) return 0;
    //     if(dp[ind][prevind+1]!=-1) return dp[ind][prevind+1];
    //     int nottake=solve(ind+1,arr,n,prevind,dp);
    //     int take=INT_MIN;
    //      if(prevind==-1 or arr[ind]>arr[prevind]){
    //         take=1+solve(ind+1,arr,n,ind,dp);
    //      }
    //     return dp[ind][prevind+1]=max(nottake,take);
    // }
    
    // int lengthOfLIS(vector<int>& nums) {
    //     int n=nums.size();
    //     vector<vector<int>>dp(n,vector<int>(n+1,-1));
    //     return solve(0,nums,n,-1,dp);
    // }
     
    
    // int lengthOfLIS(vector<int>& arr) {
    //     int n=arr.size();
    //     vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    //      for(int ind=n-1;ind>=0;ind--){
    //         for(int prevind=ind-1;prevind>=-1;prevind--){
    //             int nottake=dp[ind+1][prevind+1];
    //             int take=0;
    //             if(prevind==-1 or arr[ind]>arr[prevind]){
    //                 take=1+dp[ind+1][ind+1];
    //             }
    //             dp[ind][prevind+1]=max(take,nottake);
    //         }
    //      }
    //     return dp[0][0];
    // }
    int lengthOfLIS(vector<int>& arr) {
        int n=arr.size();
        vector<int>ahead(n+1,0);
         for(int ind=n-1;ind>=0;ind--){
            vector<int>curr(n+1,0);
            for(int prevind=ind-1;prevind>=-1;prevind--){
                int nottake=ahead[prevind+1];
                int take=0;
                if(prevind==-1 or arr[ind]>arr[prevind]){
                    take=1+ahead[ind+1];
                }
                curr[prevind+1]=max(take,nottake);
            }
            ahead=curr;
         }
        return ahead[0];
    }
};