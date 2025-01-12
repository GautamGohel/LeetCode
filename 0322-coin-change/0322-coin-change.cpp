class Solution {
public:
    
    int solve(int n,vector<int>&coins,int amount,vector<vector<int>>&dp){
        if(n==0){
            if(amount%coins[0]==0){
                return amount/coins[0];
            }
            else{
                return 1e9;
            }
        }
        if(dp[n][amount]!=-1) return dp[n][amount];
        int pick=1e9;
        if(coins[n]<=amount) pick=1+solve(n,coins,amount-coins[n],dp);
        int notpick=solve(n-1,coins,amount,dp);
        return dp[n][amount]=min(pick,notpick);
    }
  
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans=solve(n-1,coins,amount,dp);
        return ans>=1e9?-1:ans;
    }
};