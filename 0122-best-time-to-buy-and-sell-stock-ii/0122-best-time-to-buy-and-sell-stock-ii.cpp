class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>prev(2,-1);
        prev[0]=0;
        prev[1]=0;
        int profit;
        for(int i=n-1;i>=0;i--){
            vector<int>curr(2,-1);
            for(int j=0;j<=1;j++){
                if(j==0){
                    int notbuy=prev[j];
                    int buyit=-prices[i]+prev[!j];
                    profit=max(notbuy,buyit);
                }else{
                    int notsell=prev[j];
                    int sellit=prices[i]+prev[!j];
                    profit=max(sellit,notsell);
                }
                curr[j]=profit;
            }
            prev=curr;
        }
        return prev[0];
    }
};