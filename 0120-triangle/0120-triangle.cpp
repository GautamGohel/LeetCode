class Solution {
public:

    /*
    int solve(int i,int j,vector<vector<int>>& triangle,int n){
        if(i==n-1){
            return triangle[i][j];
        }
        int down=triangle[i][j]+solve(i+1,j,triangle,n);
        int diagonal=triangle[i][j]+solve(i+1,j+1,triangle,n);
        return min(down,diagonal);
    }
   
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
       return solve(0,0,triangle,n);
    }
    */
    /*
    int solve(int i,int j,vector<vector<int>>& triangle,int n,vector<vector<int>>&dp){
        if(i==n-1){
            return triangle[i][j];
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int down=triangle[i][j]+solve(i+1,j,triangle,n,dp);
        int diagonal=triangle[i][j]+solve(i+1,j+1,triangle,n,dp);
        return dp[i][j]=min(down,diagonal);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int col=triangle[n-1].size();
        vector<vector<int>>dp(n,vector<int>(col,-1));
       return solve(0,0,triangle,n,dp);
    }
   */
    int solve(int i,int j,vector<vector<int>>& triangle,int n,vector<vector<int>>&dp){
        if(i==n-1){
            return triangle[i][j];
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int down=triangle[i][j]+solve(i+1,j,triangle,n,dp);
        int diagonal=triangle[i][j]+solve(i+1,j+1,triangle,n,dp);
        return dp[i][j]=min(down,diagonal);
    }
   
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int col=triangle[n-1].size();
        vector<vector<int>>dp(n,vector<int>(col,-1));
        for(int i=0;i<col;i++){
            dp[n-1][i]=triangle[n-1][i];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                dp[i][j]=triangle[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};