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
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        int profit;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                for(int k=1;k<=2;k++){
                    if(j==0){
                        int buyit=-prices[i]+dp[i+1][!j][k];
                        int notbuy=dp[i+1][j][k];
                        profit=max(buyit,notbuy);
                    }else{
                        int sellit=prices[i]+dp[i+1][!j][k-1];
                        int notsell=dp[i+1][j][k];
                        profit=max(sellit,notsell);
                    }
                    dp[i][j][k]=profit;
                }
            }
        }
        return dp[0][0][2];
    }
};