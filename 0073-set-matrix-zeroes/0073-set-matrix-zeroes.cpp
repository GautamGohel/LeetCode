class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int>hashrow(m,0);
        vector<int>hashcol(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    hashrow[i]=1;
                    hashcol[j]=1;
                }
            }
        }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(hashrow[i]==1 or hashcol[j]==1){
                matrix[i][j]=0;
            }
        }
    }
    }
};