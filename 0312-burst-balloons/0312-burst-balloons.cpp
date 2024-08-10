class Solution {
public:

    // int solve(int i,int j,vector<int>nums,vector<vector<int>>&dp){
    //     if(i>j){
    //         return 0;
    //     }
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int maxi=0;
    //     for(int ind=i;ind<=j;ind++){
    //         int cost=nums[ind]*nums[i-1]*nums[j+1]+solve(i,ind-1,nums,dp)+solve(ind+1,j,nums,dp);
    //         maxi=max(maxi,cost);
    //     }
    //     return dp[i][j]=maxi;
    // }

    // int maxCoins(vector<int>& nums) {
    //     int maxi=0;
    //     int n=nums.size();
    //     nums.insert(nums.begin(),1);
    //     nums.push_back(1);
    //     vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    //     return solve(1,n,nums,dp);
    // }


    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));
        for(int i=n;i>=1;i--){
            for(int j=1;j<=n;j++){
                if(i>j) continue;
                 int maxi=0;
                for(int ind=i;ind<=j;ind++){
                    int cost=nums[ind]*nums[i-1]*nums[j+1]+dp[i][ind-1]+dp[ind+1][j];
                     maxi=max(maxi,cost);
                  }
                  dp[i][j]=maxi;
            }
        }
        return dp[1][n];
    }
};