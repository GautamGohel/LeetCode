class Solution {
public:

//    bool solve(int i,int j,string s, string p,vector<vector<int>>&dp){
//      if(i<0 and j<0) return true;
//      if(i<0 and j>=0) return false;
//      if(i>=0 and j<0){
//         for(int k=0;k<=i;k++){
//             if(s[k]!='*')
//             return false;
//         }
//         return true;
//      }
//      if(dp[i][j]!=-1) return dp[i][j];
//      if(s[i]==p[j] or s[i]=='?'){
//         return dp[i][j]=solve(i-1,j-1,s,p,dp);
//      }
//      if(s[i]=='*'){
//         return dp[i][j]=solve(i-1,j,s,p,dp) or solve(i,j-1,s,p,dp);
//      }
//      return false;
//    }
    
//     bool isMatch(string p, string s) {
//         int n1=s.size();
//         int n2=p.size();
//         vector<vector<int>>dp(n1,vector<int>(n2,-1));
//         return solve(n1-1,n2-1,s,p,dp);
//     }
    
    //  bool isMatch(string p, string s) {
    //     int n1 = s.size();
    //     int n2 = p.size();
    //     vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1, false));

    //     dp[0][0] = true;

    //     for (int j = 1; j <= n2; j++) {
    //         if (p[j - 1] == '*') {
    //             dp[0][j] = dp[0][j - 1];
    //         }
    //     }

    //     for (int i = 1; i <= n1; i++) {
    //         bool flag = true;
    //         for (int k = 0; k < i; k++) {
    //             if (s[k] != '*') {
    //                 flag = false;
    //                 break;
    //             }
    //         }
    //         dp[i][0] = flag;
    //     }

    //     // Fill the DP table
    //     for (int i = 1; i <= n1; i++) {
    //         for (int j = 1; j <= n2; j++) {
    //             if (s[i - 1] == p[j - 1] || s[i - 1] == '?') {
    //                 dp[i][j] = dp[i - 1][j - 1];
    //             } else if (s[i - 1] == '*') {
    //                 dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
    //             } else {
    //                 dp[i][j] = false;
    //             }
    //         }
    //     }

    //     return dp[n1][n2];
    // }

     bool isMatch(string p, string s) {
        int n1 = s.size();
        int n2 = p.size();
        vector<bool> prev(n2 + 1, false);

        prev[0] = true;

        for (int j = 1; j <= n2; j++) {
            if (p[j - 1] == '*') {
                prev[j] = prev[j - 1];
            }
        }

        for (int i = 1; i <= n1; i++) {
            vector<bool>curr(n2+1,false);
            
            bool flag = true;
            for (int k = 0; k < i; k++) {
                if (s[k] != '*') {
                    flag = false;
                    break;
                }
            }
            curr[0] = flag;
            for (int j = 1; j <= n2; j++) {
                if (s[i - 1] == p[j - 1] || s[i - 1] == '?') {
                    curr[j] = prev[j - 1];
                } else if (s[i - 1] == '*') {
                    curr[j] = prev[j] || curr[j - 1];
                } else {
                    curr[j] = false;
                }
            }
            prev=curr;
        }

        return prev[n2];
    }
};