class Solution {
public:

   long change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<double>>dp(n,vector<double>(amount+1,0));
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0) dp[0][i]=1;
            else dp[0][i]=0;
        }
        for(int i=1;i<n;i++){
            dp[i][0]=1;
            for(int j=0;j<=amount;j++){
                double pick=0;
                if(coins[i]<=j) pick=dp[i][j-coins[i]];
                double notpick=dp[i-1][j];
                dp[i][j]=pick+notpick;
            }
        }
        return (dp[n-1][amount]);
    }
};