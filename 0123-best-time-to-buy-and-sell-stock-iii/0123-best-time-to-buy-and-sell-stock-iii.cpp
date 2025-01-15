class Solution {
public:
    int solve(vector<int>&prices,int i,int buy,int n,int transactions,vector<vector<vector<int>>>&dp){
         if(i==n or transactions==0){
            return 0;
         }
         if(dp[i][buy][transactions]!=-1) return dp[i][buy][transactions];
         int profit=0;
         if(buy==0){
             int buyit=-prices[i]+solve(prices,i+1,!buy,n,transactions,dp);
             int notbuy=solve(prices,i+1,buy,n,transactions,dp);
             profit=max(buyit,notbuy);
         }else{
             int sellit=prices[i]+solve(prices,i+1,!buy,n,transactions-1,dp);
             int notsell=solve(prices,i+1,buy,n,transactions,dp);
             profit=max(sellit,notsell);
         }
        return dp[i][buy][transactions]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(prices,0,0,n,2,dp);
    }
};