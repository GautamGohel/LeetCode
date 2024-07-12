class Solution {
public:
      int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int>prev(n,0);
        for(int i=0;i<n;i++){
            prev[i]=matrix[0][i];
        }
        for(int i=1;i<n;i++){
            vector<int>curr(n,0);
            for(int j=0;j<n;j++){
               int ld=j>0?prev[j-1]:INT_MAX;
               int up=prev[j];
               int rd=j<n-1?prev[j+1]:INT_MAX;
               curr[j]=matrix[i][j]+min(ld,min(up,rd));
            }
            prev=curr;
        }
        int mini = INT_MAX;
        for (int i = 0; i < n; i++) {
            mini = min(mini, prev[i]);
        }
        return mini;
    }
};