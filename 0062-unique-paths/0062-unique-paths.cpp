class Solution {
public:
  
    int uniquePaths(int m, int n) {
        vector<int>prev(n,0);
        for(int i=0;i<m;i++){
            vector<int>curr(n,0);
            for(int j=0;j<n;j++){
                if(i==0 and j==0){
                    curr[j]=1;
                    continue;
                }
                    int up=0;
                    if(i>0) up=prev[j];
                    int left=0;
                    if(j>0) left=curr[j-1];
                    curr[j]=left+up;
            }
            prev=curr;
        }
        return prev[n-1];
    }
};