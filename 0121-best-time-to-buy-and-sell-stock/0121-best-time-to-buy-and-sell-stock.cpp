class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //brute force
        // int maxi=0;
        // int n=prices.size();
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         int val=prices[j]-prices[i];
        //         maxi=max(maxi,val);
        //     }
        // }
        // return maxi;

        int n=prices.size();
        int maxi=0;
        int mini=prices[0];
        for(int i=0;i<n;i++){
            if(prices[i]<mini){
                mini=prices[i];
            }
            int val=prices[i]-mini;
            maxi=max(maxi,val);
        }
        return maxi;
    }
};