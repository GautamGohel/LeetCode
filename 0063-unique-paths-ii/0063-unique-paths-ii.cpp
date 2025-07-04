class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        if(obstacleGrid[0][0]==1) return 0;
        dp[0][0]=1;
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
               if(row==0 and col==0) continue;
               int up=0;
               int left=0;
                if(obstacleGrid[row][col]==1){
                     dp[row][col]=0;
                     continue;
                }
                if(row>0) up+=dp[row-1][col];
                if(col>0) left+=dp[row][col-1];
               dp[row][col]=up+left;
            }
        }
        return dp[m-1][n-1];
    }
};