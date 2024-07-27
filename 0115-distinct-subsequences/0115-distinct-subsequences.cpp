class Solution {
public:

    // int solve(string s,string t,int i,int j,vector<vector<int>>dp){
    //     if(j<0) return 1;
    //     if(i<0) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(s[i]==t[j]){
    //         return solve(s,t,i-1,j-1,dp)+solve(s,t,i-1,j,dp);
    //     }
    //     return dp[i][j]=solve(s,t,i-1,j,dp);
    // }
   
    // int numDistinct(string s, string t) {
    //     int n1=s.length();
    //     int n2=t.length();
    //     vector<vector<int>>dp(n1,vector<int>(n2,-1));
    //     return solve(s,t,n1-1,n2-1,dp);
    // }

    // int numDistinct(string s, string t) {
    //     int n1=s.length();
    //     int n2=t.length();
    //     vector<vector<double>>dp(n1+1,vector<double>(n2+1,0));
    //     for(int i=0;i<=n1;i++){
    //         dp[i][0]=1;
    //     }
    //     // for(int j=1;j<=n2;j++){
    //     //     dp[0][j]=0;
    //     // } don't need as all are allready intitiallized with 0
    //     for(int i=1;i<=n1;i++){
    //         for(int j=1;j<=n2;j++){
    //              if(s[i-1]==t[j-1]){
    //                 dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
    //             }
    //             else dp[i][j]=dp[i-1][j];
    //         }
    //     }
    //     return (int)dp[n1][n2];
    // }
    int numDistinct(string s, string t) {
        int n1=s.length();
        int n2=t.length();
        vector<double>prev(n2+1,0);
            prev[0]=1;
        // for(int j=1;j<=n2;j++){
        //     dp[0][j]=0;
        // } don't need as all are allready intitiallized with 0
        for(int i=1;i<=n1;i++){
            vector<double>curr(n2+1,0);
            curr[0]=1;
            for(int j=1;j<=n2;j++){
                 if(s[i-1]==t[j-1]){
                    curr[j]=prev[j-1]+prev[j];
                }
                else curr[j]=prev[j];
            }
            prev=curr;
        }
        return (int)prev[n2];
    }
};