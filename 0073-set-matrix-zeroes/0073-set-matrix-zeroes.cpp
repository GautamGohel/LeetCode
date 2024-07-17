class Solution {
public:

// will not work on leet code as val can be negative here
// brute force O(m*n*(m+n))+m*n   
//    void markrow(vector<vector<int>>& matrix,int i,int rows,int cols){
//      for(int j=0;j<cols;j++){
//         if(matrix[i][j]!=0)
//         matrix[i][j]=-1;
//      }
//    }
//    void markcol(vector<vector<int>>& matrix,int j,int rows,int cols){
//      for(int i=0;i<rows;i++){
//         if(matrix[i][j]!=0)
//         matrix[i][j]=-1;
//      }
//    }

//   void changetozero(vector<vector<int>>& matrix,int rows,int cols){
//     for(int i=0;i<rows;i++){
//         for(int j=0;j<cols;j++){
//             if(matrix[i][j]==-1){
//                 matrix[i][j]=0;
//             }
//         }
//     }
//    }
    
//     void setZeroes(vector<vector<int>>& matrix) {
//         int rows=matrix.size();
//         int cols=matrix[0].size();
//         for(int i=0;i<rows;i++){
//             for(int j=0;j<cols;j++){
//                 if(matrix[i][j]==0){
//                     markrow(matrix,i,rows,cols);
//                     markcol(matrix,j,rows,cols);
//                 }
//             }
//         } 
//         changetozero(matrix,rows,cols);
//     }

//optimized O(2nm) sc O(m+n)
    // void setZeroes(vector<vector<int>>& matrix) {
    //     int rows=matrix.size();
    //     int cols=matrix[0].size();
    //     vector<int>col(cols,0);
    //     vector<int>row(rows,0);
    //     for(int i=0;i<rows;i++){
    //         for(int j=0;j<cols;j++){
    //             if(matrix[i][j]==0){
    //                 col[j]=1;
    //                 row[i]=1;
    //             }
    //         }
    //     }
    //     for(int i=0;i<rows;i++){
    //         for(int j=0;j<cols;j++){
    //             if(col[j] or row[i]){
    //                 matrix[i][j]=0;
    //             }
    //         }
    //     }
    // }
    void setZeroes(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        int col0=1;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j]==0){
                   matrix[i][0]=0;
                   if(j!=0)
                   matrix[0][j]=0;
                   else
                    col0=0;
                }
            }
        }
        for(int i=1;i<rows;i++){
            for(int j=1;j<cols;j++){
                if(matrix[0][j]==0 or matrix[i][0]==0){
                    matrix[i][j]=0;
                }
            }
        }
        if(matrix[0][0]==0){
            for(int i=0;i<cols;i++){
                matrix[0][i]=0;
            }
        }
        if(col0==0){
            for(int i=0;i<rows;i++){
                matrix[i][0]=0;
            }
        }
    }
};