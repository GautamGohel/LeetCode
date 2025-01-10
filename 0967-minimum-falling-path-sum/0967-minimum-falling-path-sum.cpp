class Solution {
public:
   
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int mini=INT_MAX;
        vector<int>prev(n,0);
        for(int i=0;i<n;i++){
            prev[i]=matrix[0][i];
        }
        for(int i=1;i<n;i++){
            vector<int>temp(n,0);
            for(int j=0;j<n;j++){
                int left=1e9;
                if(j>0) left=matrix[i][j]+prev[j-1];
                int top=1e9;
                if(i>0) top=matrix[i][j]+prev[j];
                int right=1e9;
                if(j<n-1) right=matrix[i][j]+prev[j+1];
                temp[j]=min(left,min(top,right));
            }
            prev=temp;
        }
        for(int i=0;i<n;i++){
            mini=min(mini,prev[i]);
        }
        return mini;
    }
};