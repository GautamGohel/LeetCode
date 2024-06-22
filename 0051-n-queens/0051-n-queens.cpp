class Solution {
public:

//       bool ispossible(int col,int row,vector<string>&board,int n){
//         int tempcol=col,temprow=row;
//         while(row>=0 and col>=0){
//             if(board[row][col]=='Q'){
//                 return false;
//             }
//             col--;
//             row--;
//         }
//         col=tempcol;
//         row=temprow;
//         while(col>=0){
//             if(board[row][col]=='Q'){
//                 return false;
//             }
//             col--;
//         }
//         col=tempcol;
//         row=temprow;
//         while(col>=0 and row<n){
//             if(board[row][col]=='Q'){
//                 return false;
//             }
//             col--;
//             row++;
//         }
//         return true;
// }

//     void solve(int col,int n,vector<string>&board,vector<vector<string>>&ans){
//         if(col==n){
//             ans.push_back(board);
//             return;
//         }
//         for(int row=0;row<n;row++){
//             if(ispossible(col,row,board,n)){
//               board[row][col]='Q';
//               solve(col+1,n,board,ans);
//               board[row][col]='.';
//             }
//         }
//     }

    void solve(int col,int n,vector<string>&board,vector<vector<string>>&ans,
     vector<int>&leftrow, vector<int>&uppardiagonal, vector<int>&lowerdiagonal){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(leftrow[row]==0 and uppardiagonal[n-1+col-row]==0 and lowerdiagonal[col+row]==0){
              board[row][col]='Q';
              leftrow[row]=1;
              uppardiagonal[n-1+col-row]=1;
              lowerdiagonal[col+row]=1;
              solve(col+1,n,board,ans,leftrow,uppardiagonal,lowerdiagonal);
              board[row][col]='.';
              leftrow[row]=0;
              uppardiagonal[n-1+col-row]=0;
              lowerdiagonal[col+row]=0;
            }
        }
    }
  
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n,string(n,'.'));
        vector<int>leftrow(n,0);
        vector<int>uppardiagonal(2*n-1,0);
        vector<int>lowerdiagonal(2*n-1,0);
        solve(0,n,board,ans,leftrow,uppardiagonal,lowerdiagonal);
        return ans;
    }
};