class Solution {
public:
   
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int ind=n-1;ind>=0;ind--){
           for(int prevind=ind-1;prevind>=-1;prevind--){
              int take=0;
              if(prevind==-1 or nums[prevind]<nums[ind]){
                  take=1+dp[ind+1][ind+1];
              }
              int nottake=dp[ind+1][prevind+1];
              dp[ind][prevind+1]=max(take,nottake);
           }
        }
        return dp[0][0];
    }
};