class Solution {
public:
   
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int mini=INT_MAX;
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            dp[0][i]=matrix[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int left=1e9;
                if(j>0) left=matrix[i][j]+dp[i-1][j-1];
                int top=1e9;
                if(i>0) top=matrix[i][j]+dp[i-1][j];
                int right=1e9;
                if(j<n-1) right=matrix[i][j]+dp[i-1][j+1];
                dp[i][j]=min(left,min(top,right));
            }
        }
        for(int i=0;i<n;i++){
            mini=min(mini,dp[n-1][i]);
        }
        return mini;
    }
};