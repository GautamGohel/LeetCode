class Solution {
public:
    
    int solve(string s1,string s2,int n1,int n2,vector<vector<int>>&dp){
        if(n1<0 or n2<0){
            return 0;
        }
        if(dp[n1][n2]!=-1) return dp[n1][n2];
        if(s1[n1]==s2[n2]){
            return dp[n1][n2]=1+solve(s1,s2,n1-1,n2-1,dp);
        }
        if(s1[n1]!=s2[n2]){
            return dp[n1][n2]=max(solve(s1,s2,n1-1,n2,dp),solve(s1,s2,n1,n2-1,dp));
        }
        return 0;
    }
  
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size();
        int n2=text2.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        dp[0][0]=0;
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                if(text1[i]==text2[j]) dp[i+1][j+1]=1+dp[i][j];
                else{
                    dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
                }
            }
        }
        return dp[n1][n2];
    }
};