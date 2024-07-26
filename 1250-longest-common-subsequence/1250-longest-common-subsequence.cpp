class Solution {
public:

    // int solve(string s1,string s2,int n1,int n2,vector<vector<int>>&dp){
    //     if(n1<0 or n2<0){
    //         return 0;
    //     }
    //     if(dp[n1][n2]!=-1) return dp[n1][n2];
    //     if(s1[n1]==s2[n2]){
    //         return dp[n1][n2]=1+solve(s1,s2,n1-1,n2-1,dp);
    //     }
    //     return dp[n1][n2]=max(solve(s1,s2,n1-1,n2,dp),solve(s1,s2,n1,n2-1,dp));
    // }
   
    // int longestCommonSubsequence(string text1, string text2) {
    //     int n1=text1.size();
    //     int n2=text2.size();
    //     vector<vector<int>>dp(n1,vector<int>(n2,-1));
    //     return solve(text1,text2,n1-1,n2-1,dp);
    // }
   
    // int longestCommonSubsequence(string text1, string text2) {
    //     int n1=text1.size();
    //     int n2=text2.size();
    //     vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
    //     //as base case is if n1 or n2 is negative return 0 we can't use negative index
    //     //so we're shifting indexes by 1 place 
    //     for(int i=0;i<=n1;i++){
    //         dp[i][0]=0;
    //     }
    //     for(int j=0;j<=n2;j++){
    //         dp[0][j]=0;
    //     }
    //     for(int i=1;i<=n1;i++){
    //         for(int j=1;j<=n2;j++){
    //             if(text1[i-1]==text2[j-1]) dp[i][j]=1+dp[i-1][j-1];
    //             else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    //         }
    //     }
    //     return dp[n1][n2];
    // }

        int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size();
        int n2=text2.size();
        vector<int>prev(n2+1,0);
        //as base case is if n1 or n2 is negative return 0 we can't use negative index
        //so we're shifting indexes by 1 place 
        for(int j=0;j<=n2;j++){
            prev[j]=0;
        }
        for(int i=1;i<=n1;i++){
            vector<int>curr(n2+1,0);
            for(int j=1;j<=n2;j++){
                if(text1[i-1]==text2[j-1]) curr[j]=1+prev[j-1];
                else curr[j]=max(prev[j],curr[j-1]);
            }
            prev=curr;
        }
        return prev[n2];
    }
};