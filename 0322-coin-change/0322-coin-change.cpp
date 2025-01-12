class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int>prev(amount+1,0);
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0) prev[i]=i/coins[0];
            else prev[i]=1e9;
        }
        for(int i=1;i<n;i++){
            vector<int>curr(amount+1,0);
            for(int j=0;j<=amount;j++){
                int pick=1e9;
                if(coins[i]<=j) pick=1+curr[j-coins[i]];
                int notpick=prev[j];
                curr[j]=min(pick,notpick);
            }
            prev=curr;
        }
        int ans=prev[amount];
        return ans>=1e9?-1:ans;
    }
};