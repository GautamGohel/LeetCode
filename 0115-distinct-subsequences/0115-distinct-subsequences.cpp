class Solution {
public:

  
    int numDistinct(string s, string t) {
        int n1=s.size();
        int n2=t.size();
        vector<double>prev(n2+1,0);
        prev[0]=1;
        for(int i=1;i<=n1;i++){
            vector<double>curr(n2+1,0);
            curr[0]=1;
            for(int j=1;j<=n2;j++){
                if(s[i-1]==t[j-1]){
                    curr[j]=prev[j-1]+prev[j];
                }else{
                    curr[j]=prev[j];
                }
            }
            prev=curr;
        }
        return (int)prev[n2];
    }
};