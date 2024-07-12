class Solution {
public:
     /*
    int solve(int i, int j, vector<vector<int>>& matrix, int n,vector<vector<int>>&dp) {
        if (j < 0 || j >= n) return INT_MAX;  
        if (i == 0) return matrix[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int ld = solve(i - 1, j - 1, matrix, n,dp);
        int up = solve(i - 1, j, matrix, n,dp);
        int rd = solve(i - 1, j + 1, matrix, n,dp);
        return dp[i][j]=matrix[i][j] + min(ld, min(up, rd));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int mini = INT_MAX;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for (int i = 0; i < n; i++) {
            mini = min(mini, solve(n - 1, i, matrix, n,dp));
        }
        return mini;
    }
    */


    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            dp[0][i]=matrix[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
               int ld=j>0?dp[i-1][j-1]:INT_MAX;
               int up=dp[i-1][j];
               int rd=j<n-1?dp[i-1][j+1]:INT_MAX;
               dp[i][j]=matrix[i][j]+min(ld,min(up,rd));
            }
        }
        int mini = INT_MAX;
        for (int i = 0; i < n; i++) {
            mini = min(mini, dp[n-1][i]);
        }
        return mini;
    }
};