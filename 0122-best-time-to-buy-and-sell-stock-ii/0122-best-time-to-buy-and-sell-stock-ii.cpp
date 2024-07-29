class Solution {
public:

    // int solve(vector<int>&prices,int i,int n,int buy,vector<vector<int>>&dp){
    //     if(i==n){
    //         return 0;
    //     }
    //     if(dp[i][buy]!=-1) return dp[i][buy];
    //     int profit=0;
    //     if(buy){
    //         int profit=max(-prices[i]+solve(prices,i+1,n,0,dp),solve(prices,i+1,n,1,dp));
    //         return dp[i][buy]=profit;
    //     }
    //     else{
    //         int profit=max(prices[i]+solve(prices,i+1,n,1,dp),solve(prices,i+1,n,0,dp));
    //         return dp[i][buy]=profit;
    //     }
    // }
     
    // int maxProfit(vector<int>& prices) {
    //     int n=prices.size();
    //     vector<vector<int>>dp(n,vector<int>(2,-1));
    //     return solve(prices,0,n,1,dp);
    // }

    // int maxProfit(vector<int>& prices) {
    //     int n=prices.size();
    //     vector<vector<int>>dp(n+1,vector<int>(2,-1));
    //     dp[n][0]=dp[n][1]=0;
    //     for(int ind=n-1;ind>=0;ind--){
    //         for(int buy=0;buy<=1;buy++){
    //             int profit=0;
    //             if(buy){
    //                 int profit=max(-prices[ind]+dp[ind+1][0],dp[ind+1][1]);
    //                 dp[ind][buy]=profit;
    //             }
    //             else{
    //                 int profit=max(prices[ind]+dp[ind+1][1],dp[ind+1][0]);
    //                 dp[ind][buy]=profit;
    //             }
    //         }
    //     }
    //     return dp[0][1];
    // }

    //space optimization
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>ahead(2,0);
        ahead[0]=ahead[1]=0;
        for(int ind=n-1;ind>=0;ind--){
        vector<int>curr(2,0);
            for(int buy=0;buy<=1;buy++){
                int profit=0;
                if(buy){
                    int profit=max(-prices[ind]+ahead[0],ahead[1]);
                    curr[buy]=profit;
                }
                else{
                    int profit=max(prices[ind]+ahead[1],ahead[0]);
                    curr[buy]=profit;
                }
            }
            ahead=curr;
        }
        return ahead[1];
    }
};