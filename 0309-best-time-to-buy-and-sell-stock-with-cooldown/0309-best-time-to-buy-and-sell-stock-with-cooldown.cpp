class Solution {
public:
    // int solve(int ind,vector<int>& prices,int n,int buy,vector<vector<int>>&dp){
    //     if(ind>=n){
    //         return 0;
    //     }
    //     if(dp[ind][buy]!=-1) return dp[ind][buy];
    //    int profit=0;
    //    if(buy){
    //       profit=max(-prices[ind]+solve(ind+1,prices,n,0,dp),solve(ind+1,prices,n,1,dp));
    //    }else{
    //      profit=max(prices[ind]+solve(ind+2,prices,n,1,dp),solve(ind+1,prices,n,0,dp));
    //    }
    //    return dp[ind][buy]=profit;
    // }

    // int maxProfit(vector<int>& prices) {
    //     int n=prices.size();
    //     vector<vector<int>>dp(n,vector<int>(2,-1));
    //     return solve(0,prices,n,1,dp);
    // }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+2,vector<int>(2,0));
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                if(buy){
                    dp[ind][buy]=max(-prices[ind]+dp[ind+1][0],dp[ind+1][1]);
                }else{
                    dp[ind][buy]=max(prices[ind]+dp[ind+2][1],dp[ind+1][0]);
                }
            }
        }
        return dp[0][1];
    }
};