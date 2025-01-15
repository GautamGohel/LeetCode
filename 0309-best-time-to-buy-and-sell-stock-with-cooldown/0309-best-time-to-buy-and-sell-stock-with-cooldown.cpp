class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>ahead(2,0);
        vector<int>ahead2(2,0);
        int profit;
        for(int i=n-1;i>=0;i--){
            vector<int>curr(2,-1);
            for(int j=0;j<=1;j++){
                if(j==0){
                    int notbuy=ahead[j];
                    int buyit=-prices[i]+ahead[!j];
                    profit=max(notbuy,buyit);
                }else{
                    int notsell=ahead[j];
                    int sellit=prices[i]+ahead2[!j];
                    profit=max(sellit,notsell);
                }
                curr[j]=profit;
            }
            ahead2=ahead;
            ahead=curr;
        }
        return ahead[0]; 
    }
};