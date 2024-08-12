class Solution {
public:

//    void editmatrix(int row,int col,int rowno,int colno,vector<vector<int>>& matrix){
//       for(int i=0;i<row;i++){
//          if(matrix[i][colno]!=0)
//          matrix[i][colno]=-1;
//       }
//       for(int j=0;j<col;j++){
//          if(matrix[rowno][j]!=0)
//         matrix[rowno][j]=-1;
//       }
//    }

//     void setZeroes(vector<vector<int>>& matrix) {
//         int row=matrix.size();
//         int col=matrix[0].size();
//         for(int i=0;i<row;i++){
//             for(int j=0;j<col;j++){
//                 if(matrix[i][j]==0){
//                     editmatrix(row,col,i,j,matrix);
//                 }
//             }
//         }
//         for(int i=0;i<row;i++){
//             for(int j=0;j<col;j++){
//                 if(matrix[i][j]==-1){
//                   matrix[i][j]=0;
//                 }
//             }
//         }
//     }

    void setZeroes(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        vector<int>rowhash(row,0);//tells if there is 0 in this row or not
        vector<int>colhash(col,0);//tells if there is 0 in this col or not
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]==0){
                    rowhash[i]=1;
                    colhash[j]=1;
                }
            }
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(rowhash[i] or colhash[j]){
                  matrix[i][j]=0;
                }
            }
        }
    }
};