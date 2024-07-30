class Solution {
public:

    // int solve(vector<int>&prices,int i,int n,int buy,vector<vector<int>>&dp,int fee){
    //     if(i==n){
    //         return 0;
    //     }
    //     if(dp[i][buy]!=-1) return dp[i][buy];
    //     int profit=0;
    //     if(buy){
    //         int profit=max(-prices[i]+solve(prices,i+1,n,0,dp,fee),solve(prices,i+1,n,1,dp,fee));
    //         return dp[i][buy]=profit;
    //     }
    //     else{
    //         int profit=max(prices[i]+solve(prices,i+1,n,1,dp,fee)-fee,solve(prices,i+1,n,0,dp,fee));
    //         return dp[i][buy]=profit;
    //     }
    // }
     
    // int maxProfit(vector<int>& prices, int fee) {
    //     int n=prices.size();
    //     vector<vector<int>>dp(n,vector<int>(2,-1));
    //     return solve(prices,0,n,1,dp,fee);
    // }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        dp[n][0]=dp[n][1]=0;
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                int profit=0;
                if(buy){
                    int profit=max(-prices[ind]+dp[ind+1][0],dp[ind+1][1]);
                    dp[ind][buy]=profit;
                }
                else{
                    int profit=max(prices[ind]+dp[ind+1][1]-fee,dp[ind+1][0]);
                    dp[ind][buy]=profit;
                }
            }
        }
        return dp[0][1];
    }
};