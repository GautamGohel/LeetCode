class Solution {
public:
  
    int minDistance(string word1, string word2) {
        int n1=word1.size();
        int n2=word2.size();
        vector<int>prev(n2+1,0);
        for(int i=0;i<=n2;i++){
            prev[i]=i;
        }
        for(int i=1;i<=n1;i++){
            vector<int>curr(n2+1,0);
            curr[0]=i;
            for(int j=1;j<=n2;j++){
                if(word1[i-1]==word2[j-1]){
                    curr[j]=prev[j-1];
                }else{
                    int deleteit=1+prev[j];
                    int replace=1+prev[j-1];
                    int insert=1+curr[j-1];
                    curr[j]=min(deleteit,min(replace,insert));
                }
            }
            prev=curr;
        }
        return prev[n2];
    }
};