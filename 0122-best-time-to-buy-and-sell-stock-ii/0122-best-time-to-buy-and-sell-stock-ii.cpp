class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        dp[n][0]=0;
        dp[n][1]=0;
        int profit;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                if(j==0){
                    int notbuy=dp[i+1][j];
                    int buyit=-prices[i]+dp[i+1][!j];
                    profit=max(notbuy,buyit);
                }else{
                    int notsell=dp[i+1][j];
                    int sellit=prices[i]+dp[i+1][!j];
                    profit=max(sellit,notsell);
                }
                dp[i][j]=profit;
            }
        }
        return dp[0][0];
    }
};