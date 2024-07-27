class Solution {
public:
    string shortestCommonSupersequence(string text1, string text2) {
            int n1=text1.size();
            int n2=text2.size();
            vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
            //as base case is if n1 or n2 is negative return 0 we can't use negative index
            //so we're shifting indexes by 1 place 
            for(int i=0;i<=n1;i++){
                dp[i][0]=0;
            }
            for(int j=0;j<=n2;j++){
                dp[0][j]=0;
            }
            for(int i=1;i<=n1;i++){
                for(int j=1;j<=n2;j++){
                    if(text1[i-1]==text2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                    else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
            int i=n1,j=n2;
            string s="";
            while(i>0 and j>0){
                if(text1[i-1]==text2[j-1]){
                   s+=text1[i-1];
                   i--;
                   j--;
                }
                else if(dp[i-1][j]==dp[i][j]){
                   s+=text1[i-1];
                   i--;
                }
                else{
                    s+=text2[j-1];
                    j--;
                }
            }
            while(i>0){
                s+=text1[i-1];
                i--;
            }
            while(j>0){
                s+=text2[j-1];
                j--;
            }
            reverse(s.begin(),s.end());
         return s;   
    }
};