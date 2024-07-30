class Solution {
public:
    // int solve(vector<int>&prices,int i,int n,int buy,vector<vector<vector<int>>>&dp,int cap){
    //     if(i==n or cap==0){
    //         return 0;
    //     }
    //     if(dp[i][buy][cap]!=-1) return dp[i][buy][cap];
    //     int profit=0;
    //     if(buy){
    //         int profit=max(-prices[i]+solve(prices,i+1,n,0,dp,cap),solve(prices,i+1,n,1,dp,cap));
    //         return dp[i][buy][cap]=profit;
    //     }
    //     else{
    //         int profit=max(prices[i]+solve(prices,i+1,n,1,dp,cap-1),solve(prices,i+1,n,0,dp,cap));
    //         return dp[i][buy][cap]=profit;
    //     }
    // }
    // int maxProfit(vector<int>& prices) {
    //     int n=prices.size();
    //     vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
    //     return solve(prices,0,n,1,dp,2);
    // }

    // int maxProfit(vector<int>& prices) {
    //     int n=prices.size();
    //     vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
    //     for(int i=0;i<n;i++){
    //         for(int buy=0;buy<=1;buy++){
    //             dp[i][buy][0]=0;
    //         }
    //     }
    //     for(int buy=0;buy<=1;buy++){
    //        for(int cap=0;cap<=2;cap++){
    //          dp[n][buy][cap]=0;
    //        }
    //     }
    //     for(int ind=n-1;ind>=0;ind--){
    //         for(int buy=0;buy<=1;buy++){
    //            for(int cap=1;cap<=2;cap++){
    //              int profit=0;
    //                 if(buy){
    //                     int profit=max(-prices[ind]+dp[ind+1][0][cap],dp[ind+1][1][cap]);
    //                     dp[ind][buy][cap]=profit;
    //                 }
    //                 else{
    //                     int profit=max(prices[ind]+dp[ind+1][1][cap-1],dp[ind+1][0][cap]);
    //                     dp[ind][buy][cap]=profit;
    //                 }
    //            }
    //         }
    //     }
    //     return dp[0][1][2];
    // }
   
   //space optimization
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>after(2,vector<int>(3,0));
        //default is already 0 so we don't have to write 0 in base case
        //     for(int buy=0;buy<=1;buy++){
        //         prev[buy][0]=0;
        //     }
      
        // for(int buy=0;buy<=1;buy++){
        //    for(int cap=0;cap<=2;cap++){
        //      dp[n][buy][cap]=0;
        //    }
        // }
        for(int ind=n-1;ind>=0;ind--){
            vector<vector<int>>curr(2,vector<int>(3,0));
            for(int buy=0;buy<=1;buy++){
               for(int cap=1;cap<=2;cap++){
                 int profit=0;
                    if(buy){
                        int profit=max(-prices[ind]+after[0][cap],after[1][cap]);
                        curr[buy][cap]=profit;
                    }
                    else{
                        int profit=max(prices[ind]+after[1][cap-1],after[0][cap]);
                        curr[buy][cap]=profit;
                    }
               }
            }
            after=curr;
        }
        return after[1][2];
    }
};