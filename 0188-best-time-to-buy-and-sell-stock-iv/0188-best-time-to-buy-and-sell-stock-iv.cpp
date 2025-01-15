class Solution {
public:
    int maxProfit(int cap, vector<int>& prices) {
         int n=prices.size();
        vector<vector<int>>prev(2,vector<int>(cap+1,0));
        int profit;
        for(int i=n-1;i>=0;i--){
        vector<vector<int>>curr(2,vector<int>(cap+1,0));
            for(int j=0;j<=1;j++){
                for(int k=1;k<=cap;k++){
                    if(j==0){
                        int buyit=-prices[i]+prev[!j][k];
                        int notbuy=prev[j][k];
                        profit=max(buyit,notbuy);
                    }else{
                        int sellit=prices[i]+prev[!j][k-1];
                        int notsell=prev[j][k];
                        profit=max(sellit,notsell);
                    }
                    curr[j][k]=profit;
                }
            }
            prev=curr;
        }
        return prev[0][cap];
    }
};