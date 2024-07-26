class Solution {
public:
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
    int longestPalindromeSubseq(string s) {
        string t=s;
        reverse(t.begin(),t.end());
        return longestCommonSubsequence(s,t);
    }
};