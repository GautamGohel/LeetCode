class Solution {
public:
  /*
    int solve(int n,vector<int>&coins, int amount,vector<vector<int>>&dp){
        if(n==0) {
            if(amount%coins[0]==0) return amount/coins[0];
            return 1e9;
        } 
        if(dp[n][amount]!=-1) return dp[n][amount];
        int nottake=solve(n-1,coins,amount,dp);
        int take=INT_MAX;
        if(coins[n]<=amount) take=1+solve(n,coins,amount-coins[n],dp);
        return dp[n][amount]=min(nottake,take);
    }
  
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans= solve(n-1,coins,amount,dp);
        if(ans>=1e9) return -1;
        return ans;
    }
    */

    /*
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        for(int T=0;T<=amount;T++){
            if(T%coins[0]==0){
                dp[0][T]=T/coins[0];
            }
            else 
              dp[0][T]=1e9;
        }
        for(int i=1;i<n;i++){
            for(int T=0;T<=amount;T++){
                int nottake=dp[i-1][T];
                int take=INT_MAX;
                if(coins[i]<=T) take=1+dp[i][T-coins[i]];
                dp[i][T]=min(take,nottake);
            }
        }
        int ans= dp[n-1][amount];
        if(ans>=1e9) return -1;
        return ans;
    }
    */
        int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int>prev(amount+1,0);
        for(int T=0;T<=amount;T++){
            if(T%coins[0]==0){
                prev[T]=T/coins[0];
            }
            else 
              prev[T]=1e9;
        }
        for(int i=1;i<n;i++){
            vector<int>curr(amount+1,0);
            for(int T=0;T<=amount;T++){
                int nottake=prev[T];
                int take=INT_MAX;
                if(coins[i]<=T) take=1+curr[T-coins[i]];
                curr[T]=min(take,nottake);
            }
            prev=curr;
        }
        int ans= prev[amount];
        if(ans>=1e9) return -1;
        return ans;
    }
};