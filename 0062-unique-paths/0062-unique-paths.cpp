class Solution {
public:
   /*
   int solve(int m,int n){
       if(m==0 and n==0) return 1;
        if(m<0 or n<0) return 0;
        int up=solve(m-1,n);
        int left=solve(m,n-1);
        return up+left;
    }
    int uniquePaths(int m, int n) {
       return solve(m-1,n-1);
    }
    */
    /*int solve(int m,int n,vector<vector<int>>&dp){
       if(m==0 and n==0) return 1;
        if(m<0 or n<0) return 0;
        if(dp[m][n]!=-1) return dp[m][n];
        int up=solve(m-1,n,dp);
        int left=solve(m,n-1,dp);
        return dp[m][n]=up+left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
       return solve(m-1,n-1,dp);
    }
    */
   /* int uniquePaths(int m, int n) {
    vector<vector<int>>dp(m,vector<int>(n,-1));
    dp[0][0]=1;
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0 and j==0) continue;
            int up=0;
            int left=0;
            if(i-1>=0) up=dp[i-1][j];
            if(j-1>=0) left=dp[i][j-1];
            dp[i][j]=up+left;
        }
       }
       return dp[m-1][n-1];
    }
    */
    int uniquePaths(int m, int n) {
    vector<int>prev(n,0);
       for(int i=0;i<m;i++){
        vector<int>temp(n,0);
        for(int j=0;j<n;j++){
            if(i==0 and j==0) {
                temp[j]=1;  
                continue;
            }
            int up=0;
            int left=0;
            if(i>0) up=prev[j];
            if(j>0) left=temp[j-1];
            temp[j]=up+left;
        }
        prev=temp;
       }
       return prev[n-1];
    }
};