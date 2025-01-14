class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n1=str1.size();
        int n2=str2.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int len=dp[n1][n2];
        int i=n1,j=n2;
        string s;
        while(i>0 and j>0){
            if(str1[i-1]==str2[j-1]){
                s+=str1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                s+=str1[i-1];
                i--;
            }else{
                s+=str2[j-1];
                j--;
            }
        }
        while(i>0){
            s+=str1[i-1];
            i--;
        }
        while(j>0){
            s+=str2[j-1];
            j--;
        }
        reverse(s.begin(),s.end());
        return s;
    }
};