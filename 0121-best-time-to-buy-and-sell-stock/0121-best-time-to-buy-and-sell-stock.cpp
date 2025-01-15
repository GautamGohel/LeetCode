class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxi=prices[n-1];
        int ans=0;
        for(int i=n-1;i>=0;i--){
            if(prices[i]<maxi){
                ans=max(ans,maxi-prices[i]);
            }else{
                maxi=prices[i];
            }
        }
        return ans;
    }
};