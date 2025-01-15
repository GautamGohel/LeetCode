class Solution {
public:


    int solve(vector<int>& prices,int i,int buy,int n,vector<vector<int>>&dp){
        if(i==n){
            return 0;
        }
        if(dp[i][buy]!=-1) return dp[i][buy];
        int profit=0;
        if(buy==0){
            int notbuy=solve(prices,i+1,buy,n,dp);
            int buyit=-prices[i]+solve(prices,i+1,!buy,n,dp);
            profit=max(notbuy,buyit);
        }
        else{
            int notsell=solve(prices,i+1,buy,n,dp);
            int sellit=prices[i]+solve(prices,i+1,!buy,n,dp);
            profit=max(sellit,notsell);
        }
        return dp[i][buy]=profit;
    }
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(prices,0,0,n,dp);
    }
};