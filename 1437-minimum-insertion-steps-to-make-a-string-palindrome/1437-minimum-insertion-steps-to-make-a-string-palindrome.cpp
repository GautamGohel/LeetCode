class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size();
        int n2=text2.size();
        vector<int>prev(n2+1,0);
        prev[0]=0;
        for(int i=1;i<=n1;i++){
            vector<int>curr(n2+1,0);
            for(int j=1;j<=n2;j++){
                if(text1[i-1]==text2[j-1]) curr[j]=1+prev[j-1];
                else{
                    curr[j]=max(prev[j],curr[j-1]);
                }
            }
            prev=curr;
        }
        return prev[n2];
    }
    int minInsertions(string s1) {
        int n=s1.size();
        string s2=s1;
        reverse(s2.begin(), s2.end());
        return n-longestCommonSubsequence(s1,s2);
    }
};