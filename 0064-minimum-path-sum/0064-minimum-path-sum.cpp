class Solution {
public:
/*
    int solve(int m,int n,vector<vector<int>>& grid){
        if(m==0 and n==0) return grid[m][n];
        if(m<0 or n<0) return INT_MAX;
        int up=solve(m-1,n,grid);
        int left=solve(m,n-1,grid);
        return min(up,left)+grid[m][n];  
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        return solve(m-1,n-1,grid);
    }
    */
    /* int solve(int m,int n,vector<vector<int>>& grid,vector<vector<int>>&dp){
        if(m==0 and n==0) return grid[m][n];
        if(m<0 or n<0) return INT_MAX;
        if(dp[m][n]!=-1) return dp[m][n];
        int up=solve(m-1,n,grid,dp);
        int left=solve(m,n-1,grid,dp);
        return dp[m][n]=min(up,left)+grid[m][n];  
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,grid,dp);
    }
    */
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int>prev(n,0);
        for(int i=0;i<m;i++){
            vector<int>curr(n,0);
            for(int j=0;j<n;j++){
                if(i==0 and j==0) curr[0]=grid[0][0];
               else{ int up=INT_MAX;
                if(i>0) up=prev[j];
                int left=INT_MAX;
                if(j>0)left=curr[j-1];
                curr[j]=grid[i][j]+min(up,left);
               }
            }
            prev=curr;
        }
        return prev[n-1];
    }
};