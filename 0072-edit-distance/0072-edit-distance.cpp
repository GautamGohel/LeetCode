class Solution {
public:
    
    int solve(string s,string t,int m,int n,vector<vector<int>>&dp){
        if(n<0) return m+1;
        if(m<0) return n+1;
        if(dp[m][n]!=-1) return dp[m][n];
        if(s[m]==t[n]){
           return dp[m][n]=solve(s,t,m-1,n-1,dp);
        }else{
            int deleteit=1+solve(s,t,m-1,n,dp);
            int replace=1+solve(s,t,m-1,n-1,dp);
            int insert=1+solve(s,t,m,n-1,dp);
            return dp[m][n]=min(deleteit,min(replace,insert));
        }
    }
  
    int minDistance(string word1, string word2) {
        int n1=word1.size();
        int n2=word2.size();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        return solve(word1,word2,n1-1,n2-1,dp);
    }
};