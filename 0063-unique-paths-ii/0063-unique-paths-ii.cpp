class Solution {
public:
/*
    int solve(int m,int n,vector<vector<int>>& obstacleGrid){
       if(m>=0 and n>=0 and obstacleGrid[m][n]==1) return 0;
       if(m==0 and n==0) return 1;
        if(m<0 or n<0) return 0;
        int up=solve(m-1,n,obstacleGrid);
        int left=solve(m,n-1,obstacleGrid);
        return up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        return solve(m-1,n-1,obstacleGrid);
    }
    */
   /*
    int solve(int m,int n,vector<vector<int>>& obstacleGrid, vector<vector<int>>dp){
       if(m>=0 and n>=0 and obstacleGrid[m][n]==1) return dp[m][n]=0;
       if(m==0 and n==0) return 1;
        if(m<0 or n<0) return 0;
        if(dp[m][n]!=-1) return dp[m][n];
        int up=solve(m-1,n,obstacleGrid,dp);
        int left=solve(m,n-1,obstacleGrid,dp);
        return dp[m][n]=up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,obstacleGrid,dp);
    }
    */
    /*
     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
      vector<vector<int>>dp(m,vector<int>(n,-1));
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if (obstacleGrid[i][j]==1) dp[i][j]=0;
            else if(i==0 and j==0){
                dp[0][0]=1;
            }
            else
            {
            int up=0;
            int left=0;
            if(i-1>=0) up=dp[i-1][j];
            if(j-1>=0) left=dp[i][j-1];
            dp[i][j]=up+left;
            }
        }
       }
       return dp[m-1][n-1];
    }
    */
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
      vector<int>prev(n,0);
       for(int i=0;i<m;i++){
        vector<int>curr(n,0);
        for(int j=0;j<n;j++){
            if (obstacleGrid[i][j]==1) curr[j]=0;
            else if(i==0 and j==0){
                curr[0]=1;
            }
            else
            {
            int up=0;
            int left=0;
            if(i-1>=0) up=prev[j];
            if(j-1>=0) left=curr[j-1];
            curr[j]=up+left;
            }
        }
        prev=curr;
       }
       return prev[n-1];
    }
};