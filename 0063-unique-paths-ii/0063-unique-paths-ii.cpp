class Solution {
public:
    
    int solve(int m,int n,vector<vector<int>>&map,vector<vector<int>>&dp){
        if(m>=0 and n>=0 and map[m][n]==1) return 0;
        if(m==0 and n==0) return 1;
        if(m<0 or n<0) return 0;
        if(dp[m][n]!=-1) return dp[m][n];
        int up=0;
        if(m>0) up=solve(m-1,n,map,dp);
        int left=0;
        if(n>0) left=solve(m,n-1,map,dp);
        return dp[m][n]=up+left;
    }
 
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,obstacleGrid,dp);
    }
};