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
    int minDistance(string word1, string word2) {
        int n1=word1.length();
        int n2=word2.length();
        return n1+n2-2*(longestCommonSubsequence(word1,word2));
    }
};