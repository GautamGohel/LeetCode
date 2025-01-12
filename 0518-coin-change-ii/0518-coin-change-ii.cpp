class Solution {
public:
 
    int solve(int n,int amount,vector<int>&coins,vector<vector<int>>&dp){
        if(n==0){
            if(amount%coins[0]==0) return 1;
            else return 0;
        }
        if(amount==0) return 1;
        if(dp[n][amount]!=-1) return dp[n][amount];
        int pick=0;
        if(coins[n]<=amount) pick=solve(n,amount-coins[n],coins,dp);
        int notpick=solve(n-1,amount,coins,dp);
        return dp[n][amount]=pick+notpick;
    }
  
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return solve(n-1,amount,coins,dp);
    }
};