class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
       //brute force
        //  int n=matrix.size();
        //  vector<vector<int>>rotated(n,vector<int>(n,0));
        //  for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         rotated[j][n-i-1]=matrix[i][j];
        //     }
        //  }
        // matrix=rotated;

        int n=matrix.size();
        for(int i=0;i<n-1;i++){
           for(int j=i+1;j<n;j++){
            swap(matrix[i][j],matrix[j][i]);
           }
        }
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};